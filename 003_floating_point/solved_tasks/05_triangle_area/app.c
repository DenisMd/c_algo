#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, x3, y3;

    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double twice = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    double shoelace = 0.5 * fabs(twice);

    double c = hypot(x2 - x1, y2 - y1);
    double b = hypot(x3 - x1, y3 - y1);
    double a = hypot(x3 - x2, y3 - y2);

    double p = (a + b + c) * 0.5;
    double heron = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("Shoelace - %.16f\n", shoelace);
    printf("Heron    - %.16f\n", heron);

    return 0;
}
