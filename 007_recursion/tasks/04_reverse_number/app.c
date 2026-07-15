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

// TODO: придумать сигнатуру и реализовать рекурсивно (без цикла).
int reverse_number(int n)
{
    return 0;
}

int main()
{
    int n;

    read_input(&n);

    printf("%d\n", reverse_number(n));

    return 0;
}
