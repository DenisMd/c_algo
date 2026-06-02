#include <stdio.h>


int main()
{
    int a = 15;
    int b = 31;

    int c = (a+b)*b - 5%a;
    printf("%d %d %d\n", a, b, c);

    a = (b = c) + 1;
    printf("%d %d %d\n", a, b, c);

    return 0;
}