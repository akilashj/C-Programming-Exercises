//
// Created by Akila Shashiduni on 2026.09.03.
//
#include <stdio.h>

int read_integer(void);

int main(void)
{
    int value;
    int total = 0;
    int count = 0;
    float average;

    printf("Enter positive numbers or negative to stop: ");
    value = read_integer();

    while (value >= 0)
    {
        if (value > 0)
        {
            total = total + value;
            count = count + 1;
        }

        printf("Enter positive numbers or negative to stop: ");
        value = read_integer();
    }

    if (count > 0)
    {
        average = (float) total / count;

        printf("You entered %d positive numbers. The average is: %.3f\n",
               count, average);
    }

    return 0;
}

int read_integer(void)
{
    int value;
    int result;

    result = scanf("%d", &value);

    while (result != 1)
    {
        printf("invalid input\n");
        scanf("%*s");

        result = scanf("%d", &value);
    }

    return value;
}