#include <stdio.h>
#include <assert.h>

int my_abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    int num;
    scanf("%d",&num); // -2147483648
    int num2 = my_abs(num);

    assert(num2 > 0);  // инвариант в программе, всегда должен исполняться

    printf("num2 = %d\n", num2);

    return 0;
}