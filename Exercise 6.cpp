//
// Created by Akila Shashiduni on 2026.09.03.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
int get_option(void);
int throw_dice(int sides);

int main(void)
{
    int option;
    int dice;

    srand(time(NULL));

    option = 0;

    while (option != 3)
    {
        menu();
        option = get_option();

        switch (option)
        {
            case 1:
                dice = throw_dice(6);
                printf("You rolled D6: %d\n", dice);
                break;

            case 2:
                dice = throw_dice(10);
                printf("You rolled D10: %d\n", dice);
                break;

            case 3:
                printf("Goodbye!\n");
                break;
        }
    }

    return 0;
}


void menu(void)
{
    printf("\n--- Dice Menu ---\n");
    printf("1. Roll D6\n");
    printf("2. Roll D10\n");
    printf("3. Quit\n");
}


int get_option(void)
{
    int option;
    int check;

    printf("Choose: ");
    check = scanf("%d", &option);

    while (check != 1 || option < 1 || option > 3)
    {
        printf("Invalid input!\n");

        if (check != 1)
        {
            scanf("%*s");
        }

        printf("Choose: ");
        check = scanf("%d", &option);
    }

    return option;
}


int throw_dice(int sides)
{
    int number;

    number = rand() % sides + 1;

    return number;
}