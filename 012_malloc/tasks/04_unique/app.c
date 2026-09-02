#include <stdbool.h>
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

int *unique(const int *a, size_t n, size_t *out_n)
{
    // TODO: выделить malloc'ом n элементов (худший случай — все уникальны),
    //       переписать туда элементы, которых там ещё нет, в порядке появления,
    //       ужать блок до реального размера через realloc и вернуть его,
    //       количество отдать через *out_n
    *out_n = 0;
    return NULL;
}

int main()
{
    int a[MAX_N];
    size_t n;

    read_input(a, &n);

    size_t m;
    int *u = unique(a, n, &m);
    if (u == NULL && n > 0) {
        fprintf(stderr, "Allocation failed!\n");
        return 1;
    }

    printf("%zu\n", m);
    print_array(u, m);

    free(u);

    return 0;
}
