//
// Created by Akila Shashiduni on 2026.09.11.
//
#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    int input;
    printf("Enter a positive number: ");
    if (scanf("%d", &input) == 1 && input > 0) {
        *value = input;
        return true;
    }
    while (getchar() != '\n'); // clear invalid input from buffer[cite: 11]
    return false;
}

int main(void) {
    int guess;
    int fail_count = 0;

    while (fail_count < 3) {
        printf("Guess how much money I have!\n");
        if (read_positive(&guess)) {
            printf("You didn't get it right. I have %d euros.\n", guess * 2 + 20);
        } else {
            printf("Incorrect input\n");
            fail_count++;
        }
    }

    printf("I give up! See you later!\n");
    return 0;
}