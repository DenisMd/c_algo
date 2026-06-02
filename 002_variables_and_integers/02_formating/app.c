#include <stdio.h>

int main()
{
    int big_number = 1000000;
    int small_number = 7;

    printf("format %.7d\n", big_number);
    printf("format %.7d\n", small_number);
    return 0;
}