//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main(void) {
    int level = 0;
    srand((unsigned int)time(NULL));

    printf("Enter debug level (0-4): ");
    if (scanf("%d", &level) != 1 || level < 0 || level > 4) {
        printf("Invalid debug level entered.\n");
        return 1;
    }

    set_debug_level(level);

    for (int i = 1; i <= 5; i++) {
        int msg_level = rand() % 5;
        dprintf(msg_level, "Log message index %d (debug level %d)\n", i, msg_level);
    }

    return 0;
}