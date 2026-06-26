#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main()
{
    double a = 0.1 + 0.2;
    double b = 0.3;

    printf("%.16f == %.16f = %d\n", a, b, a == b);
    printf("%.18f == %.18f = %d\n", a, b, a == b);

    double eps = 1e-9;
    bool is_equal = fabs(a-b) < eps; // абсолютная погрешность для небольнших чисел: проверяем что первые 9 цифр равны
    printf("%.16f == %.16f = %d\n", a, b, is_equal);

    a = 0.000001;
    b = 0.000002;
    printf("%.9f %.9f is equal : %d\n", a, b, fabs(a-b) < 1e-6);
    a = 0.0000001;
    b = 0.0000002;
    printf("%.9f %.9f is equal : %d\n", a, b, fabs(a-b) < 1e-6);

    return 0;
}