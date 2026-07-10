#include <stdio.h>
#include <stdlib.h>

void read_input(int *n)
{
    printf("Enter integer N: ");
    if (scanf("%d", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

int is_prime(int n)
{
    // TODO: реализовать проверку простоты числа
    // Проверять делители до sqrt(n)
    // Вернуть 1, если n простое, иначе 0

    return 0;
}

int main()
{
    int n;
    read_input(&n);

    printf("%d\n", is_prime(n));

    return 0;
}
