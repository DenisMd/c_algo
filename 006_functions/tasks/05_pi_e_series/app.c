#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(int *n)
{
    printf("Enter number of terms N: ");
    if (scanf("%d", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*n < 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

double my_e(int terms)
{
    // TODO: e = 1 + 1/1! + 1/2! + ...
    // term_0 = 1, term_{i+1} = term_i / (i + 1)

    return 0;
}

double my_pi_leibniz(int terms)
{
    // TODO: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + ...)

    return 0;
}

int main()
{
    int n;

    read_input(&n);

    double e = my_e(n);
    double pi = my_pi_leibniz(n);

    printf("e  ≈ %.15f  (истинное %.15f, ошибка %.2e)\n", e, M_E, fabs(e - M_E));
    printf("pi ≈ %.15f  (истинное %.15f, ошибка %.2e)\n", pi, M_PI, fabs(pi - M_PI));

    return 0;
}
