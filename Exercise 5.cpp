//
// Created by Akila Shashiduni on 2026.09.03.
//
#include <stdio.h>

int read_range(int low, int high);

int main(void)
{
    int roll;
    int round = 1;

    printf("Let's play!\n");

    while (round <= 3)
    {
        printf("Roll a die and enter your result.\n");

        roll = read_range(1, 6);

        if (roll < 6)
        {
            printf("I got %d. I win!\n", roll + 1);
        }
        else
        {
            printf("I got 6. It is a tie!\n");
        }

        round++;
    }

    printf("Better luck next time. Bye!\n");

    return 0;
}


int read_range(int low, int high)
{
    int value;

    while (1)
    {
        printf("Enter a number between %d and %d: ", low, high);

        if (scanf("%d", &value) == 1)
        {
            if (value >= low && value <= high)
            {
                return value;
            }

            printf("Invalid input!\n");
        }
        else
        {
            printf("Invalid input!\n");
            scanf("%*s");
        }
    }
}