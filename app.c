/***************************************************************************//**
 * @file
 * @brief Application code
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
// -----------------------------------------------------------------------------
//                                   Includes
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "app.h"
#include "sl_wisun_api.h"
#include "sl_wisun_ip6string.h"
#include "sl_wisun_trace_api.h"
#include "sl_sleeptimer.h"
#include "app_timestamp_and_traces.h"
#include "app_address_utils.h"
#include "wisun_test_certificates.h"
#include "sl_malloc.h"
#include "sl_simple_led_instances.h"

#define VERSION "v0.0.1"
// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------
#ifdef EFR32FG25B222F1920IM56
  #define CHIP "xG25"
#endif
#ifdef EFR32MG12P433F1024GM68
  #define CHIP "xG12"
#endif
#ifndef CHIP
  #define CHIP SL_BOARD_NAME
#endif
// Network parameters
//#define NETWORK_NAME "SCRC_FAN1.1_OFDM"
//#define NETWORK_NAME "SCRC_FAN1.1_FSK"
#define NETWORK_NAME "SCRC_FAN1.0_FSK"
//#define NETWORK_NAME "Wi-SUN Network"
#define TX_POWER 19
// Metering parameters
#define METER_PORT   1234
#define COMMAND_PORT 1235
#define REPLY_PORT   1236
#define METERING_PERIOD_MS 20*1000
// Application parameters
#define VERBOSE true
// Macros to treat possible errors
#define NO_ERROR(ret, ...)                   if (ret == SL_STATUS_OK) {app_printf_time("\n"); printf(__VA_ARGS__);}
#define IF_ERROR(ret, ...)                   if (ret != SL_STATUS_OK) {app_printf_time("\n"); printf(__VA_ARGS__);}
#define IF_ERROR_RETURN(ret, ...)            if (ret != SL_STATUS_OK) {app_printf_time("\n"); printf(__VA_ARGS__); return ret;}
#define IF_ERROR_INCR(ret, error_count, ...) if (ret != SL_STATUS_OK) {app_printf_time("\n"); printf(__VA_ARGS__); error_count++;}
// -----------------------------------------------------------------------------
//                          Static Function Declarations
// -----------------------------------------------------------------------------
sl_status_t app_open_sockets_with_Border_Router();
void app_mutex_init(void);
void app_mutex_acquire(void);
void app_mutex_release(void);
void app_process_command(sl_wisun_evt_t *evt);
void app_print_network_info(char* network_name, sl_wisun_phy_config_t phy_config);
sl_status_t app_close_sockets_with_Border_Router();


// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Static Variables
// -----------------------------------------------------------------------------
uint32_t ms_count = 0;
uint32_t sec_count = 0;
uint64_t tick_count;
uint32_t metering_period_ms;
sl_wisun_socket_id_t meter_socket_id;
sl_wisun_socket_id_t command_socket_id;
sl_wisun_socket_id_t reply_socket_id;
sl_wisun_phy_config_t phy_config;
sl_wisun_join_state_t join_state = SL_WISUN_JOIN_STATE_DISCONNECTED;
sl_wisun_join_state_t previous_join_state = 100;
static uint64_t app_join_state_ms[6];
static uint64_t app_join_state_delay_sec[6];
static uint64_t app_ms;
static uint64_t app_connection_delay;

static osMutexId_t _app_wisun_stack_mtx;
static uint32_t connected_request_status = 0;
sl_wisun_ip_address_t global_ipv6;
sl_wisun_ip_address_t border_router_ipv6;
char nickname[100];

static const osMutexAttr_t _app_wisun_stack_mtx_attr = {
  .name      = "AppWisunEmptyMutex",
  .attr_bits = osMutexRecursive,
  .cb_mem    = NULL,
  .cb_size   = 0
};
// -----------------------------------------------------------------------------
//                          Public Function Definitions
// -----------------------------------------------------------------------------
/* Wi-SUN event handler */
void sl_wisun_on_event(sl_wisun_evt_t *evt)
{
  char ipv6_string[SL_WISUN_IP_ADDRESS_SIZE];
  /////////////////////////////////////////////////////////////////////////////
  // Put your Wi-SUN event handling here!                                    //
  // This is called from Wi-SUN stack.                                       //
  // Do not call blocking functions from here!                               //
  // Protect your data during event handling!                                //
  /////////////////////////////////////////////////////////////////////////////
  app_mutex_acquire();

  switch (evt->header.id) {
    case SL_WISUN_MSG_JOIN_STATE_IND_ID: {
      join_state = evt->evt.join_state.join_state;
      break;
    }
    case SL_WISUN_MSG_CONNECTION_LOST_IND_ID: {
//      join_state = SL_WISUN_JOIN_STATE_DISCONNECTED;
      break;
    }
    case SL_WISUN_MSG_CONNECTED_IND_ID: {
      connected_request_status = evt->evt.connected.status;
      app_printf_time("\n");
      printf("[IND] Connection request complete 0x%04X\n", (uint16_t)connected_request_status);
      break;
    }
    case SL_WISUN_MSG_SOCKET_DATA_SENT_IND_ID: {
      if (evt->evt.socket_data_sent.status == SL_STATUS_OK) {
        app_printf_time("\n");
        printf("[IND] Data sent to socket %lu. ", evt->evt.socket_data_sent.socket_id);
      } else {
        app_printf_time("\n");
        printf("[Failed to sent data, error %lu (socket %lu)]\n",
               evt->evt.socket_data_sent.status,
               evt->evt.socket_data_sent.socket_id );
      }
      //sl_simple_led_turn_off(sl_led_led1.context)
      break;
    }
    case SL_WISUN_MSG_NETWORK_UPDATE_IND_ID: {
      printf("[IND] Network update (flags %lu)\n", evt->evt.network_update.flags);
      break;
    }
    case SL_WISUN_MSG_SOCKET_DATA_IND_ID: {
      printf("in msg socket");
      if (app_addresses_match(evt->evt.socket_data.remote_address, border_router_ipv6)) {
          app_printf_time("\n");
          printf("IP matched");
          printf("[IND] Border Router \n");
          //SCRC
          printf("%" PRIu32 "\n",command_socket_id);
          printf("%" PRIu32 "\n",evt->evt.socket_data.socket_id);
          if (evt->evt.socket_data.socket_id == command_socket_id) {
            printf("socket id matched");
            printf("Command (%d bytes)", evt->evt.socket_data.data_length);
            app_process_command(evt);
          }
          else{
            printf("socket id mismatched");
            printf("Command (%d bytes)", evt->evt.socket_data.data_length);
            app_process_command(evt);
          }
          printf(": %s\n", (char *)evt->evt.socket_data.data);
      } else {

        sl_wisun_ip6tos(&evt->evt.socket_data.remote_address, ipv6_string);
        app_printf_time("\n");
        printf("[IND] Received Data from %s (%u): socket %lu length %u: ",
               ipv6_string,
               evt->evt.socket_data.remote_port,
               evt->evt.socket_data.socket_id,
               evt->evt.socket_data.data_length);
        printf("%s\n", (char *)evt->evt.socket_data.data);
      }
      break;
    }
    default: {
      // Un-processed event, just display the Event id
      app_printf_time("\n");
      printf("\n[IND] Un-processed Event id 0x%x\n", evt->header.id);
      break;
    }
  }
  app_mutex_release();
}

/* App task function */
void app_task(void *args)
{
  (void) args;
  sl_status_t ret;
  uint16_t previous_join_state = 100;
  uint8_t error_count = 0;
  uint16_t print_count = 0;
  uint8_t print_period = 60;
  uint16_t loop_delay = 1000;
  uint32_t time_ms;
  const uint8_t *trusted_certificate;
  const uint8_t *device_certificate;
  const uint8_t *device_private_key;
  const sl_wisun_connection_params_t *connection_parameters;
  sl_wisun_mac_address_t mac_address;
  char msg[100];
  char ip_string[100];
  uint8_t neighbor_count;
  uint16_t msg_len;
  // init wisun stack mutex
  app_mutex_init();
  // Print application information on reset
  printf("\nWi-SUN Empty %s 22Q4_Patch1_RC1 %s (%s %s)\n", CHIP, VERSION, __DATE__, __TIME__);
  printf("sl_sleeptimer_tick_to_ms(1000000) %lu \n", sl_sleeptimer_tick_to_ms(1000000));
  app_set_all_traces(SL_WISUN_TRACE_LEVEL_DEBUG);
  sl_simple_led_init_instances();
  sl_simple_led_turn_off(sl_led_led0.context);
  sl_simple_led_turn_off(sl_led_led1.context);
  osDelay(1000);
  sl_simple_led_toggle(sl_led_led0.context);
  sl_simple_led_toggle(sl_led_led1.context);
  osDelay(1000);
  sl_simple_led_turn_off(sl_led_led0.context);
  //sl_simple_led_turn_off(sl_led_led1.context);
  printf("led init done\n");
  metering_period_ms = METERING_PERIOD_MS;
  sl_sleeptimer_init();
  sl_sleeptimer_tick64_to_ms(sl_sleeptimer_get_tick_count64(), &app_start_ms);
  app_printf_time("\n");
  trusted_certificate = WISUN_ROOT_CERTIFICATE;
  device_certificate = WISUN_CLIENT_CERTIFICATE;
  device_private_key = WISUN_CLIENT_KEY;
  ret = sl_wisun_set_trusted_certificate(
      SL_WISUN_CERTIFICATE_OPTION_IS_REF,
      strlen((const char *)trusted_certificate) + 1,
      trusted_certificate);
 IF_ERROR_INCR(ret, error_count, "[Failed: unable to set the trusted certificate: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_set_device_certificate(
      SL_WISUN_CERTIFICATE_OPTION_IS_REF | SL_WISUN_CERTIFICATE_OPTION_HAS_KEY,
      strlen((const char *)device_certificate) + 1,
      device_certificate);
  IF_ERROR_INCR(ret, error_count, "[Failed: unable to set the device certificate: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_set_device_private_key(
      SL_WISUN_PRIVATE_KEY_OPTION_IS_REF,
      strlen((const char *)device_private_key) + 1,
      device_private_key);
  IF_ERROR_INCR(ret, error_count, "[Failed: unable to set the device private key: 0x%04x]\n", (uint16_t)ret);

  connection_parameters = &SL_WISUN_PARAMS_PROFILE_TEST;
  ret = sl_wisun_set_connection_parameters(connection_parameters);
  IF_ERROR_INCR(ret, error_count, "sl_wisun_set_connection_parameters(): %lu\n", ret);

  ret = sl_wisun_set_device_type((sl_wisun_device_type_t)SL_WISUN_ROUTER);
  IF_ERROR_INCR(ret, error_count, "[Failed: unable to set device type: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_set_tx_power(TX_POWER);
  IF_ERROR_INCR(ret, error_count, "[Failed: unable to set TX power: 0x%04x]\n", (uint16_t)ret);
  char *network_name = NETWORK_NAME;
  phy_config.type = SL_WISUN_PHY_CONFIG_FAN10;
  phy_config.config.fan10.reg_domain   = SL_WISUN_REGULATORY_DOMAIN_IN;
  phy_config.config.fan10.op_class = 2;
  phy_config.config.fan10.op_mode  = 3; //50kbps
  //50kbps
//  phy_config.type = SL_WISUN_PHY_CONFIG_FAN11;
//  phy_config.config.fan11.reg_domain   = SL_WISUN_REGULATORY_DOMAIN_EU;
//  phy_config.config.fan11.chan_plan_id = 33;
//  phy_config.config.fan11.phy_mode_id  = 86; //300kbps
//
//  phy_config.type = SL_WISUN_PHY_CONFIG_FAN11;
//  phy_config.config.fan11.reg_domain   = SL_WISUN_REGULATORY_DOMAIN_EU;
//  phy_config.config.fan11.chan_plan_id = 33;
//  phy_config.config.fan11.phy_mode_id  = 5; //150kbps

  app_mutex_acquire();
  ret = sl_wisun_join((uint8_t *)network_name, &phy_config);
  //ret = sl_wisun_util_connect ((uint8_t *)network_name);
  app_mutex_release();
  IF_ERROR_INCR(ret, error_count, "Failed: sl_wisun_join(%s): %lu\n", network_name, ret);
  if (error_count) {
      printf("\n\nThere are %d setup errors. Connection will fail!\n\n", error_count);
  }
  // Print PHY options
  app_print_network_info(network_name, phy_config);
  sl_sleeptimer_tick64_to_ms(sl_sleeptimer_get_tick_count64(), &app_join_state_ms[SL_WISUN_JOIN_STATE_DISCONNECTED]);
  sl_wisun_get_join_state(&join_state);
  if (join_state != SL_WISUN_JOIN_STATE_SELECT_PAN) {
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("Join state %d: it should be %d at this stage!\n", join_state, SL_WISUN_JOIN_STATE_SELECT_PAN);
    if (connected_request_status != SL_STATUS_OK) {
        printf("  Connection request status: 0x%04X\n", (uint16_t)connected_request_status);
    printf("  Your PHY selection is probably incorrect\n");
        printf("  Check your Wi-SUN configuration settings against the selected PHY\n");
        printf("  Make sure the selected PHY is valid and part of your Wi-SUN PHY configuration\n");
    }
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    while (1) {}
  }
while (1) {
    ///////////////////////////////////////////////////////////////////////////
    // Put your application code here!                                       //
    ///////////////////////////////////////////////////////////////////////////
    app_mutex_acquire();
    tick_count = sl_sleeptimer_get_tick_count64();
    sl_sleeptimer_tick64_to_ms(tick_count, &app_ms);

    // Check join_state: event-based
    sl_wisun_get_join_state(&join_state);
    //sl_simple_led_toggle(sl_led_led0.context);

    if (join_state != previous_join_state)
      {
      // join_state changed...
      // print current join_state
      app_printf_time("\n"); printf("[Join state %u->%u] ", previous_join_state, join_state);
      previous_join_state = join_state;
      if (join_state <= SL_WISUN_JOIN_STATE_OPERATIONAL)
         {
          sl_sleeptimer_tick64_to_ms(tick_count, &app_join_state_ms[join_state]);
          if (join_state > SL_WISUN_JOIN_STATE_DISCONNECTED)
          {
              // Store transition delay
              app_join_state_delay_sec[join_state] = (app_join_state_ms[join_state] - app_join_state_ms[join_state-1])/1000;
              // Print transition delay
              app_printf_time("\n");
              printf("app_join_state_delay_sec[%d] = %llu sec\n", join_state, app_join_state_delay_sec[join_state]);
          }
         }
      if (join_state == SL_WISUN_JOIN_STATE_OPERATIONAL) {
        sl_simple_led_turn_on(sl_led_led0.context);
        sl_simple_led_turn_on(sl_led_led1.context);
        // join_state just changed to Operational...
        // Set all trace groups to level WARN
        app_set_all_traces(SL_WISUN_TRACE_LEVEL_WARN);
        // Set selected trace groups back to DEBUG
        app_set_trace(SL_WISUN_TRACE_GROUP_BOOT, SL_WISUN_TRACE_LEVEL_DEBUG);
        app_set_trace(SL_WISUN_TRACE_GROUP_RPL , SL_WISUN_TRACE_LEVEL_DEBUG);
        app_set_trace(SL_WISUN_TRACE_GROUP_SOCK, SL_WISUN_TRACE_LEVEL_DEBUG);
        app_set_trace(SL_WISUN_TRACE_GROUP_TRIC, SL_WISUN_TRACE_LEVEL_DEBUG);
        loop_delay = 500;
        print_period = metering_period_ms/loop_delay;
        print_count = 0;
        app_connection_delay = app_ms - app_start_ms;
        // Get ready to listen to the Border Router
        app_open_sockets_with_Border_Router();
        // Prepare connection message: nickname + CHIP + transition delays between join_states
        ret = sl_wisun_get_mac_address(&mac_address);
        // Store nickname as last 4 digits of IPv6 address
        msg_len = snprintf(nickname, 1024, "%02X%02X", mac_address.address[6], mac_address.address[7]);
        msg_len = snprintf(msg, 1024, "[%s] %s Operational. %8llu %8llu %8llu %8llu %8llu", nickname, CHIP,
                           app_join_state_delay_sec[1],
                           app_join_state_delay_sec[2],
                           app_join_state_delay_sec[3],
                           app_join_state_delay_sec[4],
                           app_join_state_delay_sec[5]
                           );
        // Send connection message
        ret = sl_wisun_send_on_socket(meter_socket_id, msg_len, (uint8_t *)msg);
        NO_ERROR(ret, "Sending to the meter socket: '%s'\n", msg);
        IF_ERROR(ret, "[Failed: unable to send to the meter socket: 0x%04x]\n", (uint16_t)ret);
        ret = sl_wisun_send_on_socket(reply_socket_id, msg_len, (uint8_t *)msg);
        NO_ERROR(ret, "Sending to the reply socket: '%s'\n", msg);
        IF_ERROR(ret, "[Failed: unable to send to the reply socket: 0x%04x]\n", (uint16_t)ret);

      }
    }
    // Print activity indicator
    if (join_state == SL_WISUN_JOIN_STATE_OPERATIONAL) {
        printf(".");
    } else {
        printf("-");
        sl_simple_led_toggle(sl_led_led0.context);
        sl_simple_led_toggle(sl_led_led1.context);
    }
    if (print_count % print_period == 0) {
      // Regularly print a carriage return and a timestamp
      if (join_state == SL_WISUN_JOIN_STATE_OPERATIONAL) {
        // If Operational, prepare connection time message and send it to the Border Router
        time_ms = sl_sleeptimer_tick_to_ms(tick_count) - app_join_state_ms[5];
        sl_wisun_get_neighbor_count(&neighbor_count);
        sl_wisun_ip6tos((const void *)&global_ipv6, ip_string);
        msg_len = snprintf(msg, 1024, "[%s] %s connected_time %s IPv6: %s", nickname, CHIP, app_ms_to_dhms(time_ms), ip_string);
        //sl_simple_led_turn_on(sl_led_led1.context);
//        ret = sl_wisun_send_on_socket(meter_socket_id, msg_len, (uint8_t *)msg);
//        NO_ERROR(ret, "Sending to the meter socket: '%s'. ", msg);
//        IF_ERROR(ret, "[Failed: unable to send to the meter socket: 0x%04x]\n", (uint16_t)ret);
        printf("  Sending to the meter socket\n");
      } else {
        app_printf_time("\n");
      }
    }

    // Wait for a while
    osDelay(loop_delay);
    app_mutex_release();
    ms_count += loop_delay;
    print_count++;
  }
}

// -----------------------------------------------------------------------------
//                          Static Function Definitions
// -----------------------------------------------------------------------------
void app_mutex_init() {
  _app_wisun_stack_mtx = osMutexNew(&_app_wisun_stack_mtx_attr);
  assert(_app_wisun_stack_mtx != NULL );
}

void app_mutex_acquire(void)
{
  assert(osMutexAcquire(_app_wisun_stack_mtx, osWaitForever) == osOK);
}

/* Public app core mutex unlock */
void app_mutex_release(void)
{
  assert(osMutexRelease(_app_wisun_stack_mtx) == osOK);
}
void app_check_neighbors(void) {
    char msg[100];
    sl_status_t ret;
    uint16_t msg_len;
    uint8_t neighbor_count;
    uint8_t i;
    int datarate=50;
    sl_wisun_neighbor_info_t neighbor_info;
    ret = sl_wisun_get_neighbor_count(&neighbor_count);
    IF_ERROR(ret, "[Failed: sl_wisun_get_neighbor_count() returned 0x%04x]\n", (uint16_t)ret);
    printf(" neighbor_count %d ", neighbor_count);
    sl_wisun_mac_address_t neighbor_mac_addresses[neighbor_count];
    ret = sl_wisun_get_neighbors(&neighbor_count, neighbor_mac_addresses);
    IF_ERROR(ret, "[Failed: sl_wisun_get_neighbors() returned 0x%04x]\n", (uint16_t)ret);
    printf(" neighbor_count %d\n", neighbor_count);
    for (i = 0 ; i < neighbor_count; i++) {
        printf(" neighbor %d %02x%02x : ",
               i,
               neighbor_mac_addresses->address[6],
               neighbor_mac_addresses->address[7] );
        ret = sl_wisun_get_neighbor_info(neighbor_mac_addresses, &neighbor_info);
        printf(" type     %ld\n", neighbor_info.type);
        printf(" lifetime %ld\n", neighbor_info.lifetime);
        printf(" mac_tx_count           %ld\n", neighbor_info.mac_tx_count);
        printf(" mac_tx_failed_count    %ld\n", neighbor_info.mac_tx_failed_count);
        printf(" rpl_rank %d\n", neighbor_info.rpl_rank);
        printf(" etx      %d\n", neighbor_info.etx);
        printf(" rsl_in   %d dBm\n", neighbor_info.rsl_in  -174);
        printf(" rsl_out  %d dBm\n", neighbor_info.rsl_out -174);
        msg_len = snprintf(msg, 1024,"%d,%d,%s,%d,%d,%d,%ld,%ld,%d,%02x%02x",neighbor_info.rsl_out -174,datarate,nickname,neighbor_info.rsl_in  -174,neighbor_info.etx,neighbor_info.rpl_rank,neighbor_info.mac_tx_failed_count,neighbor_info.mac_tx_count,i,
                                   neighbor_mac_addresses->address[6],
                                   neighbor_mac_addresses->address[7]);        ret = sl_wisun_send_on_socket(meter_socket_id, msg_len, (uint8_t *)msg);
        NO_ERROR(ret, "RSSI Sending to the meter socket: '%s'. ", msg);
        IF_ERROR(ret, "[Failed: unable to send to the meter socket: 0x%04x]\n", (uint16_t)ret);
    }
  }
void app_process_command(sl_wisun_evt_t *evt) {
  uint16_t len;
  uint16_t i;
  uint8_t index;
  uint8_t led_number = 100;
  sl_led_state_t led_state;
  char msg[100];
  uint16_t msg_len;
  sl_status_t ret;
  char *bytes = (char *)evt->evt.socket_data.data;
  index = 0;
  len = evt->evt.socket_data.data_length;
  // if the command is a text string, it ends with '0x00'
  if (bytes[len-1] == 0x00) {
    index = 0;
    printf("app_process_command(%s)...\n", (char *)evt->evt.socket_data.data);
    if (strncmp(bytes+index, "led ", 4)==0) {
        printf("led command\n");
        index += 4;
        if (strncmp(bytes+index, "0 ", 2)==0) {
            led_number = 0;
            index += 2;
        }
        if (strncmp(bytes+index, "1 ", 2)==0) {
            led_number = 1;
            index += 2;
        }
        if (strncmp(bytes+index, "2 ", 2)==0) {
            led_number = 2;
            index += 2;
                }
        if (strncmp(bytes+index, "3 ", 2)==0) {
            led_number = 3;
            index += 2;

                }
        if (strncmp(bytes+index, "on", 2)==0) {
            led_state = sl_simple_led_get_state(sl_simple_led_array[led_number]->context);
            if (!led_state) {
                printf("led %d on\n", led_number);
                msg_len = snprintf(msg, 1024, "%s led %d on", nickname, led_number);
                sl_simple_led_turn_on(sl_simple_led_array[led_number]->context);
            } else {
                printf("led %d was already on\n", led_number);
                msg_len = snprintf(msg, 1024, "%s led %d was already on", nickname, led_number);

            }

            printf("Sending '%s' to reply_socket_id %ld...\n", msg, reply_socket_id);
            ret = sl_wisun_send_on_socket(reply_socket_id, msg_len, (uint8_t *)msg);
            IF_ERROR(ret, "[Failed: unable to send to the reply socket: 0x%04x]\n", (uint16_t)ret);
            index += 2;
            return;
        }
        if (strncmp(bytes+index, "off", 3)==0) {
            led_state = sl_simple_led_get_state(sl_simple_led_array[led_number]->context);
            if (led_state) {
                printf("led %d off\n", led_number);
                msg_len = snprintf(msg, 1024, "%s led %d off", nickname, led_number);
                sl_simple_led_turn_off(sl_simple_led_array[led_number]->context);
            } else {
                printf("led %d was already off\n", led_number);
                msg_len = snprintf(msg, 1024, "%s led %d was already off", nickname, led_number);
            }

            printf("Sending '%s' to reply_socket_id %ld...\n", msg, reply_socket_id);
            ret = sl_wisun_send_on_socket(reply_socket_id, msg_len, (uint8_t *)msg);
            IF_ERROR(ret, "[Failed: unable to send to the reply socket: 0x%04x]\n", (uint16_t)ret);
            index += 3;
            return;
        }
        if (strncmp(bytes+index, "state", 5)==0) {
            led_state = sl_simple_led_get_state(sl_simple_led_array[led_number]->context);
            if (led_state) {
                printf("led %d state is on\n",  led_number);
                msg_len = snprintf(msg, 1024, "%s led %d on", nickname, led_number);
            } else {
                printf("led %d state is off\n",  led_number);
                msg_len = snprintf(msg, 1024, "%s led %d off", nickname, led_number);
            }
            printf("Sending '%s' to reply_socket_id %ld...\n", msg, reply_socket_id);
            ret = sl_wisun_send_on_socket(reply_socket_id, msg_len, (uint8_t *)msg);
            IF_ERROR(ret, "[Failed: unable to send to the reply socket: 0x%04x]\n", (uint16_t)ret);
            index += 5;
            return;
        }
        if (strncmp(bytes+index, "data", 4)==0) {
            app_check_neighbors();
            index += 4;
            return;
                }
    }
  } else {
    printf("app_process_command(raw) %d bytes\n", evt->evt.socket_data.data_length);
    for (i=0; i< len; i++) {
        printf("[%d] %c\n", i, bytes[i]);
        if (bytes[i] == 0x00) break;
    }
    printf("Processed %d bytes\n", i);
  }
}

void app_print_network_info(char* network_name, sl_wisun_phy_config_t phy_config) {
  if (phy_config.type == SL_WISUN_PHY_CONFIG_FAN10) {
      printf("sl_wisun_join(\"%s\", FAN1.0 reg_domain %d  op_class %d  op_mode %X  fec %d);\n", network_name,
             phy_config.config.fan10.reg_domain,
             phy_config.config.fan10.op_class,
             phy_config.config.fan10.op_mode,
             phy_config.config.fan10.fec
      );
  }
  if (phy_config.type == SL_WISUN_PHY_CONFIG_FAN11) {
      printf("sl_wisun_join(\"%s\", FAN1.1 reg_domain %d  phy_mode_id %d  chan_plan_id %X);\n", network_name,
             phy_config.config.fan11.reg_domain,
             phy_config.config.fan11.phy_mode_id,
             phy_config.config.fan11.chan_plan_id
      );
  }
  if (phy_config.type == SL_WISUN_PHY_CONFIG_EXPLICIT) {
      printf("sl_wisun_join(\"%s\", EXPLICIT ch0_frequency_khz %lu  number_of_channels %d  channel_spacing %d  phy_mode_id %X);\n", network_name,
             phy_config.config.explicit.ch0_frequency_khz,
             phy_config.config.explicit.number_of_channels,
             phy_config.config.explicit.channel_spacing,
             phy_config.config.explicit.phy_mode_id
      );
  }
}

sl_status_t app_open_sockets_with_Border_Router()
{
  sl_status_t ret;

  tick_count = sl_sleeptimer_get_tick_count();

  printf("\n");

  ret = sl_wisun_get_ip_address(SL_WISUN_IP_ADDRESS_TYPE_GLOBAL, &global_ipv6);
  IF_ERROR_RETURN(ret, "[Failed: unable to retrieve the Global IPv6: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_get_ip_address(SL_WISUN_IP_ADDRESS_TYPE_BORDER_ROUTER, &border_router_ipv6);
  IF_ERROR_RETURN(ret, "[Failed: unable to retrieve the Border Router IPv6: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_open_socket (SL_WISUN_SOCKET_PROTOCOL_UDP, &meter_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to open the meter socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_connect_socket(meter_socket_id, &border_router_ipv6, METER_PORT);
  IF_ERROR_RETURN(ret, "[Failed: unable to connect the meter socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_open_socket (SL_WISUN_SOCKET_PROTOCOL_UDP, &command_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to open the command socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_bind_socket(command_socket_id, &global_ipv6, COMMAND_PORT);
  IF_ERROR_RETURN(ret, "[Failed: unable to bind the command socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_open_socket (SL_WISUN_SOCKET_PROTOCOL_UDP, &reply_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to open the reply socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_connect_socket(reply_socket_id, &border_router_ipv6, REPLY_PORT);
  IF_ERROR_RETURN(ret, "[Failed: unable to connect the reply socket: 0x%04x]\n", (uint16_t)ret);

  return SL_STATUS_OK;
}
sl_status_t app_close_sockets_with_Border_Router()
{
  sl_status_t ret;

  tick_count = sl_sleeptimer_get_tick_count();

  printf("\n");

  ret = sl_wisun_close_socket (meter_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to close the meter socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_close_socket (command_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to close the command socket: 0x%04x]\n", (uint16_t)ret);

  ret = sl_wisun_close_socket (reply_socket_id);
  IF_ERROR_RETURN(ret, "[Failed: unable to close the reply socket: 0x%04x]\n", (uint16_t)ret);

  return SL_STATUS_OK;
}

