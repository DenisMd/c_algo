#include <stdio.h>


int main()
{
    int a,b;

    scanf("%d%d",&a,&b);
    // -----------------------------
    // Не трогайте то что выше
    // TODO: напишите свой код здесь


    int temp;
    temp = a;
    a = b;
    b = temp;


    // -----------------------------
    // Не трогайте то что ниже
    printf("a = %d, b = %d\n",a,b);

    return 0;
}