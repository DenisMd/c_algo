#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(double a[], size_t *n, size_t *m)
{
    printf("Enter n, a, m: ");
    if (scanf("%zu", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*n > MAX_N) {
        fprintf(stderr, "Too many elements (max %d)!\n", MAX_N);
        exit(1);
    }
    for (size_t i = 0; i < *n; i++) {
        if (scanf("%lf", &a[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
    if (scanf("%zu", m) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

void print_array(const double a[], size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%g", a[i]);
        if (i + 1 < n) {
            printf(" ");
        }
    }
    printf("\n");
}

double *resample(const double *a, size_t n, size_t m)
{
    // TODO: выделить malloc'ом массив из m double и заполнить его
    //       линейной интерполяцией исходного:
    //       pos = j * (n - 1) / (m - 1), i = (size_t)pos, frac = pos - i,
    //       res[j] = a[i] + frac * (a[i+1] - a[i])
    //       n == 0 или m == 0 -> NULL; n == 1 или m == 1 -> все элементы a[0];
    //       на правом краю соседа a[i+1] нет
    return NULL;
}

int main()
{
    double a[MAX_N];
    size_t n, m;

    read_input(a, &n, &m);

    double *res = resample(a, n, m);
    if (res == NULL && n > 0 && m > 0) {
        fprintf(stderr, "Allocation failed!\n");
        return 1;
    }

    size_t len = (n == 0) ? 0 : m; // из пустого входа интерполировать нечего
    print_array(res, len);

    free(res);

    return 0;
}
