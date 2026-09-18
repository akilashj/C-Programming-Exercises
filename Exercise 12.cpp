//
// Created by Akila Shashiduni on 2026.09.18.
//
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int count_words(const char *str, const char *word) {
    if (str == NULL || word == NULL || strlen(word) == 0) {
        return 0;
    }

    int count = 0;
    size_t word_len = strlen(word);
    const char *ptr = str;

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += word_len;
    }

    return count;
}

int main(void) {
    char text[BUFFER_SIZE];
    char word[BUFFER_SIZE];

    while (1) {
        printf("Enter a string: ");
        if (fgets(text, sizeof(text), stdin) == NULL) {
            break;
        }
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }

        printf("Enter a word to count: ");
        if (fgets(word, sizeof(word), stdin) == NULL) {
            break;
        }
        len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        if (strcmp(word, "stop") == 0) {
            break;
        }

        int occurrences = count_words(text, word);
        printf("The word '%s' occurred %d time(s).\n\n", word, occurrences);
    }

    return 0;
}