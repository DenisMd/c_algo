#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(int a[], size_t *n, int *target)
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
    if (scanf("%d", target) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

bool two_sum(const int a[], size_t n, int target, size_t *i, size_t *j)
{
    // TODO: перебрать все пары индексов (i, j) с j > i;
    //       если a[i] + a[j] == target — записать индексы в *i, *j и вернуть true.
    //       если пары нет — вернуть false.

    return false;
}

int main()
{
    int a[MAX_N];
    size_t n;
    int target;

    read_input(a, &n, &target);

    size_t i, j;
    if (two_sum(a, n, target, &i, &j)) {
        printf("%zu %zu\n", i, j);
    } else {
        printf("нет пары\n");
    }

    return 0;
}
