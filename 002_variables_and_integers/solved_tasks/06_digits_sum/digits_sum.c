#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    int num;
    scanf("%d", &num);
    int first_digit,second_digith,third_digit;
    first_digit = num / 100;
    second_digith = (num % 100) / 10;
    third_digit = num % 10;

    printf("sum: %d\n", first_digit+second_digith+third_digit);

    return 0;
}