#include <stdio.h>


// поэксперементируйте с разными знаками
int main()
{
    int a,b;

    printf("Enter 2 numbers:\n");
    scanf("%d%d", &a, &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("a+b = %d\n", (a+b));
    printf("a-b = %d\n", (a-b));
    printf("a*b = %d\n", (a*b));
    printf("a/b = %d\n", (a/b));
    printf("a%%b = %d\n", (a%b));


    return 0;
}