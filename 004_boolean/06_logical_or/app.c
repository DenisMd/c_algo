#include <stdio.h>
#include <stdbool.h>


int main()
{
    bool a = false;
    bool b = false;
    
    printf("-------------- OR Truth Table --------------\n\n");
    printf("%d || %d = %d\n",a,b, a||b);

    a = false; b = true;
    printf("%d || %d = %d\n",a,b, a||b);
    
    a = true; b = false;
    printf("%d || %d = %d\n",a,b, a||b);
    
    a = true; b = true;
    printf("%d || %d = %d\n",a,b, a||b);

    return 0;
}