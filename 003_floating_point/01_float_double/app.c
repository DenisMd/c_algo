#include <stdio.h>


int main()
{
    float a = 43240.123456789123456789; // 6-7 значащих цифр
    double b = 43240.123456789123456789; // 15-16 значащих цифр

    printf("a = %.16f\n",a);
    printf("b = %.16lf\n",b);

    double d = 0.1 + 0.2;
    printf("double: 0.1+0.2 = %.18lf\n", d);
    printf("double: 0.3     = %.18lf\n", 0.3);

    return 0;
}