//
// Created by Akila Shashiduni on 2026.09.11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    unsigned int numbers[20];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 19; i++) {
        numbers[i] = (rand() % 20) + 1;
    }
    numbers[19] = 0;

    for (int i = 0; i < 20; i++) {
        printf("%u\n", numbers[i]);
    }

    unsigned int target;
    while (1) {
        printf("Enter number to search for (0 to stop): ");
        if (scanf("%u", &target) != 1) {
            while (getchar() != '\n');
            printf("Invalid input\n");
            continue;
        }

        if (target == 0) {
            break;
        }

        int index = find_first(numbers, target);
        if (index != -1) {
            printf("Number found at index %d\n", index);
        } else {
            printf("not found\n");
        }
    }

    return 0;
}