#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = true;
    bool b = false;
    bool c = true;

    printf("-------------- idempotency --------------\n");
    printf("a && a == a:  %d\n", (a && a) == a);
    printf("a || a == a:  %d\n", (a || a) == a);

    printf("\n-------------- commutativity --------------\n");
    printf("a && b == b && a:  %d\n", (a && b) == (b && a));
    printf("a || b == b || a:  %d\n", (a || b) == (b || a));

    printf("\n-------------- associativity --------------\n");
    printf("(a && b) && c == a && (b && c):  %d\n",
           ((a && b) && c) == (a && (b && c)));
    printf("(a || b) || c == a || (b || c):  %d\n",
           ((a || b) || c) == (a || (b || c)));

    printf("\n-------------- distributivity --------------\n");
    printf("a && (b || c) == (a && b) || (a && c):  %d\n",
           (a && (b || c)) == ((a && b) || (a && c)));
    printf("a || (b && c) == (a || b) && (a || c):  %d\n",
           (a || (b && c)) == ((a || b) && (a || c)));

    printf("\n-------------- absorption --------------\n");
    printf("a && (a || b) == a:  %d\n", (a && (a || b)) == a);
    printf("a || (a && b) == a:  %d\n", (a || (a && b)) == a);

    printf("\n-------------- de Morgan --------------\n");
    printf("!(a && b) == !a || !b:  %d\n", !(a && b) == (!a || !b));
    printf("!(a || b) == !a && !b:  %d\n", !(a || b) == (!a && !b));

    printf("\n-------------- excluded middle --------------\n");
    a = true;
    printf("a || !a == 1 (a=1):  %d\n", (a || !a) == 1);
    a = false;
    printf("a || !a == 1 (a=0):  %d\n", (a || !a) == 1);

    printf("\n-------------- contradiction --------------\n");
    a = true;
    printf("a && !a == 0 (a=1):  %d\n", (a && !a) == 0);
    a = false;
    printf("a && !a == 0 (a=0):  %d\n", (a && !a) == 0);

    a = true;
    b = false;

    printf("\n-------------- constants --------------\n");
    printf("a && 1 == a:  %d\n", (a && 1) == a);
    printf("a && 0 == 0:  %d\n", (a && 0) == 0);
    printf("a || 1 == 1:  %d\n", (a || 1) == 1);
    printf("a || 0 == a:  %d\n", (a || 0) == a);

    printf("\n-------------- double negation --------------\n");
    a = true;
    printf("!!a == a (a=1):  %d\n", !!a == a);
    a = false;
    printf("!!a == a (a=0):  %d\n", !!a == a);

    return 0;
}
