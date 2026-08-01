#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(int a[], size_t *n)
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
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
}

long max_subarray(const int a[], size_t n)
{
    // TODO: алгоритм Кадане за один проход.
    //       cur — лучшая сумма подотрезка, оканчивающегося на текущем элементе;
    //       если cur <= 0, начинаем новый подотрезок. максимум — не с нуля, а с a[0].
    //       сумму копить в long.

    return 0;
}

int main()
{
    int a[MAX_N];
    size_t n;

    read_input(a, &n);

    printf("%ld\n", max_subarray(a, n));

    return 0;
}
