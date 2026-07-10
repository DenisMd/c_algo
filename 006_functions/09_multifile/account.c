#include <stdio.h>
#include "account.h"  // свой же заголовок: компилятор проверит, что
                      // реализация совпадает с объявлениями

// ---- Реализация модуля "счёт" ----
// Здесь живёт КАК всё работает. main.c этого не видит и знать не должен.

// Определение глобальной переменной — ровно одно на всю программу.
// (в account.h была только объявлена через extern)
double balance = 0.0;

void deposit(double amount)
{
    balance += amount;
    printf("Пополнение: +%.2f\n", amount);
}

int withdraw(double amount)
{
    if (amount > balance) {
        printf("Отказ: не хватает средств (нужно %.2f, есть %.2f)\n", amount, balance);
        return 0;
    }
    balance -= amount;
    printf("Снятие:     -%.2f\n", amount);
    return 1;
}

void show_balance(void)
{
    printf("Баланс:      %.2f\n", balance);
}
