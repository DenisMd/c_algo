#include <stdio.h>

int main()
{
    int amount, hour, is_foreign, distance_km;
    int is_new_recipient, is_card_present, tx_last_hour;

    scanf("%d %d %d %d %d %d %d",
          &amount, &hour, &is_foreign, &distance_km,
          &is_new_recipient, &is_card_present, &tx_last_hour);

    int is_card_theft = amount > 50000 && is_foreign && is_card_present == 0;
    int is_account_takeover = is_new_recipient && distance_km > 500
        && (hour < 6 || hour >= 23);
    int is_velocity_attack = amount > 200000 && tx_last_hour > 5;

    int is_fraud = is_card_theft || is_account_takeover || is_velocity_attack;

    printf("%d\n", is_fraud);

    return 0;
}
