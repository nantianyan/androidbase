//yxd

#ifndef __MY_LOG__
#define __MY_LOG__

#include <stdio.h>

#define ALOGV printf
#define ALOGD printf
#define ALOGI printf
#define ALOGW printf
#define ALOGE printf

#define SLOGD printf
#define SLOGE printf

//@sa <log/log.h>
#define ALOG_ASSERT(cond, ...) LOG_FATAL_IF(!(cond), ## __VA_ARGS__)

#define LOG_FATAL_IF(cond, ...) LOG_ALWAYS_FATAL_IF(cond, ## __VA_ARGS__)

#define LOG_ALWAYS_FATAL_IF(cond, ...) \
    ( ((cond)) \
          ? ((void)printf("LOG_ALWAYS_FATAL_IF"__VA_ARGS__)) \
              : (void)0 )

#define LOG_ALWAYS_FATAL(...) \
    printf(__VA_ARGS__); (void)0

#define ALOGW_IF(cond, ...) \
        ( (cond) \
              ? ((void) printf("ALOGW_IF"__VA_ARGS__)) \
              : (void)0 )

#endif // __MY_LOG__
