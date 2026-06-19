#include <stdio.h>
#include <math.h>


//x^2 + 100000x + 1 = 0 
int main()
{
    double a = 1.0, b = 1e5, c = 1.0;
    double d = b*b - 4*a*c;
    double sqrt_d = sqrt(d);

    double x1 = (-b - sqrt_d) / (2*a);          // большой по модулю корень
    double x2_standard = (-b + sqrt_d) / (2*a); // катастрофическое сокращение
    double x2_alt = c / (a * x1);              // устойчивая формула

    printf("b               = %.15f\n", b);
    printf("sqrt_d          = %.15f\n", sqrt_d);
    printf("x1              = %.15f\n", x1);
    printf("x2 (standard)   = %.15f\n", x2_standard);
    printf("x2 (alternative)= %.15f\n", x2_alt);

    return 0;
}