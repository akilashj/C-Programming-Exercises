//
// Created by Akila Shashiduni on 2026.08.27.
//
#include <stdio.h>

int main(void)
{
    float bus, taxi, balance;
    int choice;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus);

    printf("Enter price of taxi: ");
    scanf("%f", &taxi);

    printf("How much money you have: ");
    scanf("%f", &balance);

    while (balance >= bus || balance >= taxi)
    {
        printf("You have %.2f euros left.\n", balance);
        printf("Do you want to take\n");
        printf("1) bus (%.2f euros)\n", bus);
        printf("2) taxi (%.2f euros)\n", taxi);
        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice == 1 && balance >= bus)
        {
            balance -= bus;
        }
        else if (choice == 2 && balance >= taxi)
        {
            balance -= taxi;
        }
        else
        {
            printf("Not enough money or wrong selection.\n");
        }
    }

    printf("You have %.2f euros left.\n", balance);
    printf("You need to walk. Bye\n");

    return 0;
}