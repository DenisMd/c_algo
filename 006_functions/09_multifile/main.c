#include "account.h"  // подключаем интерфейс счёта.
                      // main.c ничего не знает о его внутренностях —
                      // только о функциях из заголовка.

int main()
{
    show_balance();   // 0.00

    deposit(1000);
    deposit(500);
    show_balance();   // 1500.00

    withdraw(2000);   // отказ — не хватает
    withdraw(300);    // ок
    show_balance();   // 1200.00

    return 0;
}
