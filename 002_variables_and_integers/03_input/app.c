#include <stdio.h>


int main()
{
    int a=0,b=0;

    printf("Enter 2 numbers:\n");
    scanf("%d%d", &a, &b); // & for change variable

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}