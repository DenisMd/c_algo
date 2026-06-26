#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);

    int is_leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    printf("%d\n", is_leap);

    return 0;
}
