#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    bool is_odd = n % 2;

    printf("%d\n", is_odd);

    return 0;
}
