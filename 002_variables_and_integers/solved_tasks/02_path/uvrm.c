#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    int v0, a, t;
    int path;

    scanf("%d%d%d", &v0, &a, &t);

    path = v0*t + (a*t*t)/2;

    printf("path - %d meters\n", path);

    return 0;
}