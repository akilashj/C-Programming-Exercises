//
// Created by Akila Shashiduni on 2026.08.27.
//
#include <stdio.h>

int main(void)
{
    float monthlyIncome[12];
    float monthlyTax[12];
    float normalRate;
    float extraRate;
    float yearlyLimit;
    float sum = 0;
    int i;

    printf("Enter tax rate: ");
    scanf("%f", &normalRate);

    printf("Enter income limit: ");
    scanf("%f", &yearlyLimit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &extraRate);

    for (i = 0; i < 12; i++)
    {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &monthlyIncome[i]);

        sum = sum + monthlyIncome[i];

        if (sum <= yearlyLimit)
        {
            monthlyTax[i] = monthlyIncome[i] * normalRate / 100;
        }
        else
        {
            float incomeOverLimit = sum - yearlyLimit;

            if (incomeOverLimit >= monthlyIncome[i])
            {
                monthlyTax[i] = monthlyIncome[i] * extraRate / 100;
            }
            else
            {
                float normalIncome = monthlyIncome[i] - incomeOverLimit;

                monthlyTax[i] =
                    normalIncome * normalRate / 100 +
                    incomeOverLimit * extraRate / 100;
            }
        }
    }

    printf("\nMonth     Income       Tax\n");

    for (i = 0; i < 12; i++)
    {
        printf("%5d %10.2f %10.2f\n",
               i + 1, monthlyIncome[i], monthlyTax[i]);
    }

    return 0;
}