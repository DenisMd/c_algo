#include <stdio.h>
#include <stdlib.h>

void read_input(int *a, int *n)
{
    printf("Enter a and n: ");
    if (scanf("%d %d", a, n) != 2) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*n < 0) {
        fprintf(stderr, "negative exponent is not supported!\n");
        exit(1);
    }
}

long long power(int a, int n)
{
    // TODO: вычислить a в степени n рекурсивно (без цикла и без pow)

    return 0;
}

int main()
{
    int a, n;

    read_input(&a, &n);

    printf("%lld\n", power(a, n));

    return 0;
}
