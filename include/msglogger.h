#ifndef __MSGLOGGER_H_
#define __MSGLOGGER_H_

enum msgtype {
    DEBUG,
    INFO,
    WARN,
    ERROR,
}; 

void logger(enum msgtype type, char* service_name, const char* format, ...);

#endif //__MSGLOGGER_H_
