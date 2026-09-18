//
// Created by Akila Shashiduni on 2026.09.18.
//
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int replace_char(char *str, const char *repl) {

    if (repl == NULL || strlen(repl) != 2) {
        return 0;
    }

    char target = repl[0];
    char replacement = repl[1];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            str[i] = replacement;
            count++;
        }
    }

    return count;
}

int main(void) {
    char text[BUFFER_SIZE];
    char repl[BUFFER_SIZE];

    printf("Enter string to modify: ");
    if (fgets(text, sizeof(text), stdin) != NULL) {
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }
    }

    printf("Enter two characters (target and replacement): ");
    if (fgets(repl, sizeof(repl), stdin) != NULL) {
        size_t len = strlen(repl);
        if (len > 0 && repl[len - 1] == '\n') {
            repl[len - 1] = '\0';
        }
    }

    int count = replace_char(text, repl);

    if (count > 0) {
        printf("Replaced %d character(s).\n", count);
        printf("Modified string: %s\n", text);
    } else {
        printf("String was not modified\n");
    }

    return 0;
}