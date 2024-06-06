/***************************************************************************//**
 * @file
 * @brief LED Driver Instances
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "sl_simple_led.h"
#include "em_gpio.h"
#include "sl_simple_led_led0_config.h"
#include "sl_simple_led_led1_config.h"
#include "sl_simple_led_led2_config.h"
#include "sl_simple_led_led3_config.h"

sl_simple_led_context_t simple_led0_context = {
  .port = SL_SIMPLE_LED_LED0_PORT,
  .pin = SL_SIMPLE_LED_LED0_PIN,
  .polarity = SL_SIMPLE_LED_LED0_POLARITY,
};

const sl_led_t sl_led_led0 = {
  .context = &simple_led0_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};
sl_simple_led_context_t simple_led1_context = {
  .port = SL_SIMPLE_LED_LED1_PORT,
  .pin = SL_SIMPLE_LED_LED1_PIN,
  .polarity = SL_SIMPLE_LED_LED1_POLARITY,
};

const sl_led_t sl_led_led1 = {
  .context = &simple_led1_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};
sl_simple_led_context_t simple_led2_context = {
  .port = SL_SIMPLE_LED_LED2_PORT,
  .pin = SL_SIMPLE_LED_LED2_PIN,
  .polarity = SL_SIMPLE_LED_LED2_POLARITY,
};

const sl_led_t sl_led_led2 = {
  .context = &simple_led2_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};
sl_simple_led_context_t simple_led3_context = {
  .port = SL_SIMPLE_LED_LED3_PORT,
  .pin = SL_SIMPLE_LED_LED3_PIN,
  .polarity = SL_SIMPLE_LED_LED3_POLARITY,
};

const sl_led_t sl_led_led3 = {
  .context = &simple_led3_context,
  .init = sl_simple_led_init,
  .turn_on = sl_simple_led_turn_on,
  .turn_off = sl_simple_led_turn_off,
  .toggle = sl_simple_led_toggle,
  .get_state = sl_simple_led_get_state,
};

const sl_led_t *sl_simple_led_array[] = {
  &sl_led_led0,
  &sl_led_led1,
  &sl_led_led2,
  &sl_led_led3
};

void sl_simple_led_init_instances(void)
{
  sl_led_init(&sl_led_led0);
  sl_led_init(&sl_led_led1);
  sl_led_init(&sl_led_led2);
  sl_led_init(&sl_led_led3);
}
