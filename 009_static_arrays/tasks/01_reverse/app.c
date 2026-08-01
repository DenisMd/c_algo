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

void reverse(int a[], size_t n)
{
    // TODO: развернуть массив на месте, без второго массива
    //       (два индекса навстречу, обмен пар до середины n / 2)
}

int main()
{
    int a[MAX_N];
    size_t n;

    read_input(a, &n);

    reverse(a, n);

    print_array(a, n);

    return 0;
}
