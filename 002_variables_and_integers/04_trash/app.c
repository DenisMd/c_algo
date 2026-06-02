#include <stdio.h>


int main()
{

    int a,b,c;

    printf("%d %d %d\n",a,b,c); // UB - read uninitialized variables

    return 0;
}