//
// Created by Akila Shashiduni on 2026.09.18.
//
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    char input[BUFFER_SIZE];

    while (1) {
        printf("Enter a string: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        printf("Length: %zu\n", len);

        if (strcmp(input, "stop") == 0) {
            break;
        }
    }

    return 0;
}