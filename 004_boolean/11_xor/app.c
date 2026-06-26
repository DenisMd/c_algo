#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = false;
    bool b = false;

    printf("-------------- XOR Truth Table --------------\n\n");
    printf("%d != %d = %d\n", a, b, a != b);

    a = false; b = true;
    printf("%d != %d = %d\n", a, b, a != b);

    a = true; b = false;
    printf("%d != %d = %d\n", a, b, a != b);

    a = true; b = true;
    printf("%d != %d = %d\n", a, b, a != b);

    // скидка, если распродажа или промокод, но не оба сразу
    bool on_sale = true;
    bool has_promo = false;
    bool discount_allowed = on_sale != has_promo;

    return 0;
}
