extern uint64_t app_start_ms;

void app_printf_time(char *prefix);
sl_status_t app_set_all_traces(uint8_t trace_level);
sl_status_t app_set_trace(uint8_t group_id, uint8_t trace_level);
char* app_ms_to_dhms(uint64_t time_ms);
