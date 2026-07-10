#include <stdio.h>

// Практический пример: расчёт итоговой цены в магазине.
// Задачу "посчитать чек" разбиваем на маленькие функции —
// каждая отвечает за один шаг. Функции переиспользуются и
// вызывают друг друга.

// Цена за нужное количество товара
double subtotal(double price, int quantity)
{
    return price * quantity;
}

// Применить скидку (percent = 20 значит -20%)
double apply_discount(double amount, double percent)
{
    return amount - amount * percent / 100.0;
}

// Добавить налог (percent = 8 значит +8%)
double add_tax(double amount, double percent)
{
    return amount + amount * percent / 100.0;
}

// Общая функция: считает итоговую цену за весь заказ.
// Внутри вызывает другие функции — собирает результат по шагам.
double calculate_total(double price, int quantity, double discount, double tax)
{
    double total = subtotal(price, quantity);
    total = apply_discount(total, discount);
    total = add_tax(total, tax);
    return total;
}

int main()
{
    // Теперь весь расчёт — это один вызов.
    double total = calculate_total(250.0, 3, 20, 8); // цена, штук, скидка%, налог%
    printf("Итого к оплате: %.2f\n", total);

    // Легко посчитать другой заказ — просто другой вызов.
    printf("Второй заказ:   %.2f\n", calculate_total(99.90, 10, 5, 8));

    return 0;
}
