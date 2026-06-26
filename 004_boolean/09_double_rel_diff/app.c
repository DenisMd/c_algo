#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main()
{

    double c = 1e201;
    double d = 1.00000001e201;
    double diff = fabs(c-d);

    double largest = fmax(fabs(c), fabs(d));

    printf("c = %e, d = %e\n", c, d);
    printf("diff = %e\n", diff);
    printf("largest = %e\n", largest);
    printf("diff/largest = %f%%\n", diff/largest * 100);

    double rel_eps = 1e-6; // %
    bool is_equal = diff/largest < rel_eps;
    printf("is equal = %d\n", is_equal);


    return 0;
}