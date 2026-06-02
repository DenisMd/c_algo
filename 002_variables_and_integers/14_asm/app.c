#include <stdio.h>

//gcc -S -masm=intel app.c
int main()
{
    int a = 5;
    int b = a + 5;
    long long c = b * 500;
    long long d = c + 50;
    return 0;
}