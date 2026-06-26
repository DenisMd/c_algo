#include <stdio.h>
#include <stdbool.h>


bool print_true()
{
    printf("YOU CALL print_true\n");

    return true;
}

bool print_false()
{
    printf("YOU CALL print_false\n");

    return false;
}
int main()
{

    // print_true() && print_true();
    // print_true() || print_true();
    // print_false() && print_true();

    // int a=10,b=20;
    // print_true() && (a=b);
    // print_false() && (a=b);
    // printf("a=%d b=%d\n", a, b);

    return 0;
}