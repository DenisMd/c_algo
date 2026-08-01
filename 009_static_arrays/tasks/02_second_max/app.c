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

bool second_max(const int a[], size_t n, int *second)
{
    // TODO: за один проход найти наибольшее значение, строго меньшее максимума.
    //       дубликаты максимума не считаются: в {5,5,3} ответ 3.
    //       вернуть true и записать ответ в *second, иначе вернуть false.

    return false;
}

int main()
{
    int a[MAX_N];
    size_t n;

    read_input(a, &n);

    int second;
    if (second_max(a, n, &second)) {
        printf("%d\n", second);
    } else {
        printf("нет второго максимума\n");
    }

    return 0;
}
