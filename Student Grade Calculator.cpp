//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 50
#define NAME_SIZE 64

typedef struct {
    char name[NAME_SIZE];
    int score;
    int grade;
} Subject;

int main(void) {
    printf("Welcome to the Student Grade Calculator!%s\n", COLOR_CYAN);
    return 0;
}