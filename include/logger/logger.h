#ifndef Logger

#define Logger

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef void (*loggerfunc) (const char* str);

void bindLogger(void (*func) (const char* str));
loggerfunc logger(void (*func) (const char* str));

void logInfo(const char* str);
void logDebug(const char* str);
void logWarning(const char* str);
void logError(int code, const char* str);

#endif