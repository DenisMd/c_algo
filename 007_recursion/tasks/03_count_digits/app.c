#include <stdio.h>
#include <stdlib.h>

void read_input(int *n)
{
    printf("Enter n: ");
    if (scanf("%d", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

int count_digits(int n)
{
    // TODO: посчитать количество цифр в числе рекурсивно (без цикла)

    return 0;
}

int main()
{
    int n;

    read_input(&n);

    printf("%d\n", count_digits(n));

    return 0;
}
