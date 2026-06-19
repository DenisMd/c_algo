#include <stdio.h>
#include <math.h>

int main()
{
    double P, r, t;
    scanf("%lf%lf%lf", &P, &r, &t);

    double A1   = P * pow(1.0 + r / 1.0,       1.0 * t);
    double A12  = P * pow(1.0 + r / 12.0,     12.0 * t);
    double A365 = P * pow(1.0 + r / 365.0,   365.0 * t);
    double A1e6 = P * pow(1.0 + r / 1e6,   1e6 * t);
    double Acont = P * exp(r * t);

    printf("A1    - %f\n", A1);
    printf("A12   - %f\n", A12);
    printf("A365  - %f\n", A365);
    printf("A1e6  - %f\n", A1e6);
    printf("Acont - %f\n", Acont);
    printf("Delta - %e\n", Acont - A1e6);

    return 0;
}
