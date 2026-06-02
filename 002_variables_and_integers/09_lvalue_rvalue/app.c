#include <stdio.h>


int main()
{
    int a = 5;
    int b = 3;

    a + 1 = b; // error
    1 + (a = b); // ok

    return 0;
}