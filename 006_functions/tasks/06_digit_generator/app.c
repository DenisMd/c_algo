#include <stdio.h>
#include <stdlib.h>

void read_input(int *d, int *k)
{
    printf("Enter denominator d and count k: ");
    if (scanf("%d %d", d, k) != 2) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    // d >= 2: только для правильной дроби 1/d = 0.что-то работает деление в столбик
    if (*d < 2 || *k < 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

int next_digit(int denom)
{
    // TODO: вернуть следующую десятичную цифру дроби 1/denom
    // Остаток хранить в static-переменной между вызовами
    // остаток *= 10; цифра = остаток / denom; остаток %= denom;

    return 0;
}

int main()
{
    int d, k;

    read_input(&d, &k);

    printf("1/%d = 0.", d);
    for (int i = 0; i < k; i++) {
        printf("%d", next_digit(d));
    }
    printf("\n");

    return 0;
}
