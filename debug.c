//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdarg.h>
#include "debug.h"


static int current_debug_level = 0;

void set_debug_level(int debug_level) {
    current_debug_level = debug_level;
}

int dprintf(int debug_level, const char *fmt, ...) {
    if (debug_level <= current_debug_level) {
        va_list args;
        char buffer[256];
        int count = 0;

        va_start(args, fmt);
        count = vsprintf(buffer, fmt, args);
        va_end(args);

        fprintf(stderr, "[DBG%d] %s", debug_level, buffer);
        return count;
    }
    return 0;
}