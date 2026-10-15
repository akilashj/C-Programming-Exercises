//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 50
#define NAME_SIZE 64

#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m"
#define COLOR_GREEN  "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_CYAN   "\033[1;36m"
#define COLOR_BOLD   "\033[1m"

typedef struct {
    char name[NAME_SIZE];
    int score;
    int grade;
} Subject;

int read_int(const char *prompt, int min, int max);

int main(void) {
    printf("%sWelcome to the Student Grade Calculator!%s\n", COLOR_CYAN, COLOR_RESET);

    int count = read_int("How many subjects do you want to calculate grades for? ", 1, MAX_SUBJECTS);
    printf("Configured for %d subjects.\n", count);

    return 0;
}

int read_int(const char *prompt, int min, int max) {
    int val;
    char buffer[64];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &val) == 1 && val >= min && val <= max) {
                return val;
            }
        }
        printf("%sInvalid input! Please enter a number between %d and %d.%s\n", COLOR_RED, min, max, COLOR_RESET);
    }
}