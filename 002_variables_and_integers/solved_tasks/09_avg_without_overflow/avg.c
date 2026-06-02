#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    int n1,n2;
    int avg;
    scanf("%d%d", &n1,&n2);

    avg = n1/2 + n2/2 + (n1%2 + n2%2)/2;

    printf("avg = %d\n",avg);


    return 0;
}