#include <stdio.h>
#include <stdlib.h>

void read_input(long long *number)
{
    printf("Enter card number: ");
    if (scanf("%lld", number) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*number <= 0) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

int luhn_check(long long number)
{
    // TODO: алгоритм Луна
    // Идти справа налево: digit = number % 10; number /= 10;
    // Каждую вторую цифру (нечётная позиция справа) удвоить,
    // и если результат > 9 — вычесть 9. Всё сложить.
    // Вернуть 1, если сумма делится на 10, иначе 0.

    return 0;
}

int main()
{
    long long number;

    read_input(&number);

    printf("%d\n", luhn_check(number));

    return 0;
}
