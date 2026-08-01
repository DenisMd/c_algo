#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(double price[], size_t *n, size_t *w)
{
    printf("Enter n: ");
    if (scanf("%zu", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*n < 1 || *n > MAX_N) {
        fprintf(stderr, "Need 1..%d elements!\n", MAX_N);
        exit(1);
    }
    for (size_t i = 0; i < *n; i++) {
        if (scanf("%lf", &price[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
    if (scanf("%zu", w) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*w < 1 || *w > *n) {
        fprintf(stderr, "Need 1 <= w <= n!\n");
        exit(1);
    }
}

void moving_average(const double price[], size_t n, size_t w, double sma[])
{
    // TODO: заполнить sma[]. для i < w-1 положить NAN (окна ещё нет).
    //       для i >= w-1 — среднее w последних цен. считай скользящей суммой O(n).
}

size_t golden_crosses(const double price[], const double sma[], size_t n, size_t w, size_t days[])
{
    // TODO: вернуть число дней, где price пересекает sma снизу вверх, и записать
    //       их индексы в days[]. условие: price[i-1] < sma[i-1] && price[i] > sma[i].
    //       проверять с i = w (нужны определённые sma[i-1] и sma[i]).

    return 0;
}

int main()
{
    double price[MAX_N];
    size_t n, w;

    read_input(price, &n, &w);

    double sma[MAX_N];
    moving_average(price, n, w, sma);

    size_t days[MAX_N];
    size_t cnt = golden_crosses(price, sma, n, w, days);

    printf("%zu\n", cnt);
    for (size_t i = 0; i < cnt; i++) {
        printf("%zu%s", days[i], (i + 1 < cnt) ? " " : "");
    }
    printf("\n");

    return 0;
}
