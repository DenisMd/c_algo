#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    double v, angle, g, D;
    scanf("%lf %lf %lf %lf", &v, &angle, &g, &D);
    assert(v > 0);
    assert(g > 0);
    assert(angle > 0 && angle < M_PI / 2);

    int hits = v * v * sin(2 * angle) / g >= D;

    printf("%d\n", hits);

    return 0;
}
