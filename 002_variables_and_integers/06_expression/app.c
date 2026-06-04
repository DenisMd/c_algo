#include <stdio.h>


int super_func()
{
    return 5;
}


int main()
{
    int a = 15;
    int b = 31;

    int c = (a+b)*b - 5%super_func();
    printf("%d %d %d\n", a, b, c);

    a = (b = c) + 1;
    printf("%d %d %d\n", a, b, super_func());

    return 0;
}
