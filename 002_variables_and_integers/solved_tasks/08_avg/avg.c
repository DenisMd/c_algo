#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    int n1,n2,n3;
    int avg;
    scanf("%d%d%d",&n1,&n2,&n3);
    avg = n1+n2+n3;
    avg /= 3;

    printf("avg = %d\n", avg);

    return 0;
}