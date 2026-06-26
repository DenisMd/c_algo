#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    bool A = a;
    bool B = b;
    bool C = c;

    int at_least_two = (A && B) || (A && C) || (B && C);
    int at_least_two_b = A+B+C >= 2;

    printf("%d\n", at_least_two);

    return 0;
}
