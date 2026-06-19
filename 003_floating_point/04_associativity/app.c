#include <stdio.h>

int main()
{
    double a = 1e20;
    double b = -1e20;
    double c = 1.0;

    double sum1 = (a + b) + c;   // (1e20 - 1e20) + 1 = 0 + 1 = 1
    double sum2 = a + (b + c);   // 1e20 + (-1e20 + 1) = 1e20 - 1e20 = 0

    printf("(a+b)+c = %.15f\n", sum1);   // 1.000000000000000
    printf("a+(b+c) = %.15f\n", sum2);   // 0.000000000000000

    return 0;
}