//
// Created by Akila Shashiduni on 2026.10.03.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int shift_amount;
    srand((unsigned int)time(NULL));

    while (1) {
        printf("Enter a number between 0 and 15 (negative to stop): ");
        if (scanf("%d", &shift_amount) != 1) {

            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }

        if (shift_amount < 0) {
            break;
        }

        if (shift_amount > 15) {
            printf("Number must be between 0 and 15!\n");
            continue;
        }


        unsigned int random_num = (unsigned int)rand();
        printf("Random number in hex: 0x%X\n", random_num);


        unsigned int shifted = random_num >> shift_amount;


        unsigned int result = shifted & 0x3F;


        printf("Result (bits 0-5): %02X\n\n", result);
    }

    return 0;
}
