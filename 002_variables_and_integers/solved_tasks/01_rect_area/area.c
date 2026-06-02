#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    int width,length;
    int area,perimeter;

    scanf("%d%d", &width, &length);

    area = width * length;
    perimeter = 2 * (length+width);

    printf("Area - %d square meters\n", area);
    printf("Perimeter - %d meters\n", perimeter);

    return 0;
}