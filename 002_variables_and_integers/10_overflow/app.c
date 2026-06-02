#include <stdio.h>
#include <limits.h>

int main()
{
    int a = INT_MAX;
    int b = a+1; // Undefined Behavior : Overflow

    unsigned int c = UINT_MAX;
    unsigned int d = c+1; // Undefined Behavior : Overflow

    printf("a = %d, b = %d\n", a, b);
    printf("c = %u, d = %u\n", c, d);

    return 0;
}