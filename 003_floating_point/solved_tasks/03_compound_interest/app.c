#include <stdio.h>
#include <math.h>

int main()
{
    double principal;
    double rate;
    double years;

    scanf("%lf%lf%lf", &principal, &rate, &years);

    double compound = principal * pow(1.0 + rate, years);
    double simple = principal * (1.0 + rate * years);
    double effective_rate = pow(1.0 + rate / 12.0, 12.0) - 1.0;

    printf("Compound amount - %f\n", compound);
    printf("Simple amount   - %f\n", simple);
    printf("Effective rate  - %f\n", effective_rate);

    return 0;
}
