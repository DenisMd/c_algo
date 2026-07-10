#include <stdio.h>
#include <stdlib.h>

void read_input(double *base, int *exp)
{
    printf("Enter base and exp: ");
    if (scanf("%lf %d", base, exp) != 2) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

double my_pow(double base, int exp)
{
    // TODO: вычислить base в степени exp циклом (без pow)
    // Не забыть про exp == 0 и отрицательный exp

    return 0;
}

int main()
{
    double base;
    int exp;

    read_input(&base, &exp);

    printf("%f\n", my_pow(base, exp));

    return 0;
}
