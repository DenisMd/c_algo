#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    // это не совсем инвариант и так лучше не делать, но пока можно :)
    assert(a > 0);
    assert(b > 0);
    assert(c > 0);

    bool is_triangle = a + b > c && a + c > b && b + c > a;

    printf("%d\n", is_triangle);

    return 0;
}
