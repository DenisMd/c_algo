#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_B 1000

void read_input(double data[], size_t *n, size_t *b)
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
        if (scanf("%lf", &data[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
    if (scanf("%zu", b) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*b < 1 || *b > MAX_B) {
        fprintf(stderr, "Need 1..%d bins!\n", MAX_B);
        exit(1);
    }
}

void histogram(const double data[], size_t n, size_t b, int bins[])
{
    // TODO: найди границы сам — минимум и максимум data. затем разложи по b
    //       корзинам равной ширины на [min, max]. значение ровно max -> корзина b-1.
    //       особый случай: все значения равны (ширина 0) -> клади всё в корзину 0.
    //       формулу номера корзины выведи сам. индекс держи в [0, b-1].
}

int main()
{
    double data[MAX_N];
    size_t n, b;

    read_input(data, &n, &b);

    int bins[MAX_B];
    histogram(data, n, b, bins);

    for (size_t k = 0; k < b; k++) {
        printf("%zu: %d\n", k, bins[k]);
    }

    return 0;
}
