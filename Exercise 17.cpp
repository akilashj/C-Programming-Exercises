//
// Created by Akila Shashiduni on 2026.10.03.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool generate_password(char *target, int max_size, const char *word) {
    if (target == NULL || word == NULL) {
        return false;
    }

    size_t word_len = strlen(word);
    size_t required_len = word_len * 2 + 1;


    if ((int)required_len + 1 > max_size) {
        return false;
    }

    size_t pos = 0;

    target[pos++] = (char)((rand() % 95) + 32);

    for (size_t i = 0; i < word_len; i++) {
        target[pos++] = word[i];
        target[pos++] = (char)((rand() % 95) + 32);
    }

    target[pos] = '\0';
    return true;
}

int main(void) {
    char word[32];
    char password[128];

    srand((unsigned int)time(NULL));

    while (1) {
        printf("Enter a word (or 'stop' to quit): ");
        if (fgets(word, sizeof(word), stdin) == NULL) {
            break;
        }


        size_t len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        if (strcmp(word, "stop") == 0) {
            break;
        }

        if (generate_password(password, sizeof(password), word)) {
            printf("Generated password: %s\n\n", password);
        } else {
            printf("Error: Password does not fit in the provided buffer!\n\n");
        }
    }

    return 0;
}