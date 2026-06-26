#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, cx, cy, R, S;
    scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &cx, &cy, &R, &S);

    double dx = x - cx;
    double dy = y - cy;

    int in_circle = dx * dx + dy * dy <= R * R;
    int in_square_strict = fabs(dx) < S / 2 && fabs(dy) < S / 2;

    int result = in_circle && !in_square_strict;

    printf("%d\n", result);

    return 0;
}
