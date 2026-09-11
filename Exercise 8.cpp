//
// Created by Akila Shashiduni on 2026.09.11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}

int main(void) {
    int numbers[15];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 15; i++) {
        numbers[i] = rand();
    }

    print_numbers(numbers, 15);
    return 0;
}