#include <stdio.h>

int main()
{
    double rate_ab, rate_bc, rate_ca;
    scanf("%lf %lf %lf", &rate_ab, &rate_bc, &rate_ca);

    int is_profitable = rate_ab * rate_bc * rate_ca > 1;

    printf("%d\n", is_profitable);

    return 0;
}
