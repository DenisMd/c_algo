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
    if (*n > MAX_N) {
        fprintf(stderr, "Too many elements (max %d)!\n", MAX_N);
        exit(1);
    }
    for (size_t i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
}

void print_array(const int a[], size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i + 1 < n) {
            printf(" ");
        }
    }
    printf("\n");
}

int rle(const int *a, size_t n, int **out_vals, int **out_runs, size_t *out_n)
{
    // TODO: посчитать число серий, выделить под них два массива (значения и длины),
    //       заполнить их и отдать через out_vals / out_runs / out_n
    //       вторая аллокация упала -> освободить первую и вернуть -1
    *out_vals = NULL;
    *out_runs = NULL;
    *out_n = 0;
    return -1;
}

int *rle_decode(const int *vals, const int *runs, size_t n, size_t *out_n)
{
    // TODO: сложить длины серий, выделить массив такого размера
    //       и повторить vals[i] ровно runs[i] раз
    //       runs[i] <= 0 -> NULL
    *out_n = 0;
    return NULL;
}

int main()
{
    int a[MAX_N];
    size_t n;

    read_input(a, &n);

    int *vals, *runs;
    size_t k;

    if (rle(a, n, &vals, &runs, &k) != 0) {
        fprintf(stderr, "Allocation failed!\n");
        return 1;
    }

    printf("%zu\n", k);
    print_array(vals, k);
    print_array(runs, k);

    size_t m;
    int *back = rle_decode(vals, runs, k, &m);
    if (back == NULL && k > 0) {
        fprintf(stderr, "Decode failed!\n");
        free(vals);
        free(runs);
        return 1;
    }

    print_array(back, m);

    free(back);
    free(vals);
    free(runs);

    return 0;
}
