#include <stdio.h>
#include <stdbool.h>

int main()
{

    bool a = true;
    bool not_a = !a;

    bool b = false;
    bool not_b = !b;

    printf("a=%d, not a = %d\n", a, not_a);
    printf("b=%d, not b = %d\n", b, not_b);

    // examples
    // number_of_room == 5
    // not: number_of_room != 5

    // age >= 18
    // not: age < 18

    // number_of_room > 2
    // not: number_of_room <= 2

    return 0;
}