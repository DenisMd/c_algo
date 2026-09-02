#include <stdio.h>
#include <stdlib.h>

void read_input(double *start, double *stop, size_t *n)
{
    printf("Enter start stop n: ");
    if (scanf("%lf %lf %zu", start, stop, n) != 3) {
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

double *linspace(double start, double stop, size_t n)
{
    // TODO: выделить malloc'ом массив из n double и заполнить сеткой
    //       a[i] = start + i * (stop - start) / (n - 1)
    //       n == 0 -> NULL; n == 1 -> {start}; a[n-1] присвоить ровно stop
    return NULL;
}

int main()
{
    double start, stop;
    size_t n;

    read_input(&start, &stop, &n);

    double *a = linspace(start, stop, n);
    if (a == NULL && n > 0) {
        fprintf(stderr, "Allocation failed!\n");
        return 1;
    }

    print_array(a, n);

    free(a);

    return 0;
}
