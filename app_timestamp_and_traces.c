/***************************************************************************//**
 * @file
 * @brief Application code
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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
#include "sl_sleeptimer.h"
#include "sl_wisun_trace_api.h"
#include "sl_malloc.h"
#include "app_timestamp_and_traces.h"

uint64_t app_start_ms;
char time_str[100];

void app_printf_time(char *prefix)
{
  uint64_t current_ms;
  sl_sleeptimer_tick64_to_ms(sl_sleeptimer_get_tick_count64(), &current_ms);
  printf("%s", prefix);
  printf("[%s] ", app_ms_to_dhms(current_ms - app_start_ms));
}

sl_status_t app_set_all_traces(uint8_t trace_level) {
  sl_status_t ret;
  sl_wisun_trace_group_config_t *trace_config;
  uint8_t group_count;
  uint8_t i;
  trace_config = sl_malloc(SL_WISUN_TRACE_GROUP_COUNT * sizeof(sl_wisun_trace_group_config_t));
  group_count = SL_WISUN_TRACE_GROUP_RF+1;

  for (i = 0; i < group_count; i++) {
      trace_config[i].group_id = i;
      trace_config[i].trace_level = trace_level;
  }
  ret = sl_wisun_set_trace_level(group_count, trace_config);
  printf("\nSet all %d trace groups to DEBUG: %lu\n", group_count, ret);

  return ret;
}

sl_status_t app_set_trace(uint8_t group_id, uint8_t trace_level)
{
  sl_status_t ret;
  sl_wisun_trace_group_config_t trace_config;

  trace_config.group_id = group_id;
  trace_config.trace_level = trace_level;
  ret = sl_wisun_set_trace_level(1, &trace_config);
  printf("Set trace group %u to %u: %lu\n", group_id, trace_level, ret);
  return ret;
}

char* app_ms_to_dhms (uint64_t time_ms) {
  uint32_t msecs, secs,  mins, hours, days;
  msecs = time_ms % 1000;
  secs =  time_ms / 1000 % 60;
  mins =  time_ms / 1000 / 60 % 60;
  hours = time_ms / 1000 / 60 / 60 % 24;
  days =  time_ms / 1000 / 60 / 60 / 24;
  snprintf(time_str, 100, "%02lu day %02lu:%02lu:%02lu.%03lu", days, hours, mins, secs, msecs);
  return time_str;
}
