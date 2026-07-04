#include <stdio.h>


int main()
{
    int a;
    if (scanf("%d",&a) != 1) {
        fprintf(stderr, "incorrect input!\n");
        return 1;
    }

    if (a = 5) {
        printf("a is 5\n");
    } else {
        printf("a is not 5\n");
    }

    return 0;
}