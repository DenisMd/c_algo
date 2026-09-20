#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "fraction.h"

void read_fraction(struct fraction* f)
{
    if (scanf("%d %d", &f->num, &f->den) != 2 || f->den == 0) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
}

void read_input(struct fraction* a, struct fraction* b)
{
    printf("Enter two fractions (num den): ");
    read_fraction(a);
    read_fraction(b);
}

void print_line(struct fraction a, struct fraction b, struct fraction res,
                char op)
{
    fraction_print(a);
    printf(" %c ", op);
    fraction_print(b);
    printf(" = ");
    fraction_print(res);
    printf("\n");
}

int main()
{
    struct fraction a, b;

    read_input(&a, &b);

    a = fraction_reduce(a);
    b = fraction_reduce(b);

    struct fraction sum = fraction_add(a, b);
    struct fraction product = fraction_mul(a, b);

    assert(sum.den > 0 && product.den > 0);  // знаменатель после сокращения

    print_line(a, b, sum, '+');
    print_line(a, b, product, '*');

    return 0;
}
