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
    // TODO: вернуть 1, если n простое, иначе 0

    return 0;
}

void print_prime_numbers_to_n(int n)
{
    // TODO: вывести все простые числа от 1 до n, каждое на своей строке
}

int main()
{
    int n;
    read_input(&n);

    print_prime_numbers_to_n(n);

    return 0;
}
