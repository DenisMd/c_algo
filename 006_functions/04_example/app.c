#include <stdio.h>
#include <assert.h>

// Практический пример: расчёт итоговой цены в магазине.
// Задачу "посчитать чек" разбиваем на маленькие функции —
// каждая отвечает за один шаг. Функции переиспользуются и
// вызывают друг друга.

// Цена за нужное количество товара
double subtotal(double price, int quantity)
{
    assert(price >= 0.0);
    assert(quantity >= 0);
    return price * quantity;
}

// Применить скидку (percent = 20 значит -20%)
double apply_discount(double amount, double percent)
{
    assert(amount >= 0.0);
    assert(percent >= 0.0 && percent <= 100.0);
    return amount - amount * percent / 100.0;
}

// Добавить налог (percent = 8 значит +8%)
double add_tax(double amount, double percent)
{
    assert(amount >= 0.0);
    assert(percent >= 0.0 && percent <= 100.0);
    return amount + amount * percent / 100.0;
}

// Общая функция: считает итоговую цену за весь заказ.
// Внутри вызывает другие функции — собирает результат по шагам.
double calculate_total(double price, int quantity, double discount, double tax)
{
    assert(price >= 0.0);
    assert(quantity >= 0);
    assert(discount >= 0.0 && discount <= 100.0);
    assert(tax >= 0.0 && tax <= 100.0);
    double total = subtotal(price, quantity);
    total = apply_discount(total, discount);
    total = add_tax(total, tax);
    assert(total >= 0.0);
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
