#include <stdio.h>
#include <math.h>

// gcc app.c -lm
int main()
{
    double a;
    scanf("%lf", &a);

    printf("sqrt(%lf) = %.6lf\n", a, sqrt(a));

    return 0;
}