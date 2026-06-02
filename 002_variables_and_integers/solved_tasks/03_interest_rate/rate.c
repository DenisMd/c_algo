#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    const int KOPECK_IN_RUB = 100; // копеек в 1 рубле

    
    int deposit_rub, interest_percent;
    int deposit_kopek;
    int balance_1_year_kopek;
    int balance_2_year_kopek;
    scanf("%d%d", &deposit_rub, &interest_percent);

    deposit_kopek = deposit_rub * KOPECK_IN_RUB;
    balance_1_year_kopek = deposit_kopek + (deposit_kopek*interest_percent/100);
    balance_2_year_kopek = balance_1_year_kopek + (balance_1_year_kopek*interest_percent/100);

    printf("final sum - %d rub, %d kopeck\n", balance_2_year_kopek/KOPECK_IN_RUB, balance_2_year_kopek%KOPECK_IN_RUB);


    return 0;
}