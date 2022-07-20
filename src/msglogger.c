#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#include "msglogger.h"

#define WARNING_TXT         "WARN"
#define ERROR_TXT           "ERROR"
#define DEBUG_TXT           "DEBUG"
#define INFO_TXT            "INFO"

char* get_msg_type(enum msgtype type) {
    switch(type) {
        case(DEBUG):
            return DEBUG_TXT;
        case(INFO):
            return INFO_TXT;
        case(WARN):
            return WARNING_TXT;
        case(ERROR):
            return ERROR_TXT;
    }
}

void logger(enum msgtype type, char* service_name, const char* format, ... ) {
    time_t current_time_ms = time(NULL);
    struct tm current_time = *localtime(&current_time_ms);

    va_list arglist;

    printf("[%s %02d:%02d:%02d %02d-%02d-%04d] %s: ", 
                get_msg_type(type), 
                current_time.tm_hour, current_time.tm_min, current_time.tm_sec,
                current_time.tm_mday, current_time.tm_mon, 1900 + current_time.tm_year,
                service_name);

    va_start(arglist, format);
    vprintf(format, arglist);
    va_end(arglist );

    printf("\n");
}