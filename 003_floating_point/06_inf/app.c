#include <stdio.h>
#include <math.h>


int main()
{
    double x = 1e155, y = 1e155, z = 1e155;

    double naive = sqrt(x*x + y*y + z*z);          // inf
    double safe  = hypot(hypot(x, y), z);         // корректно

    printf("naive length = %e\n", naive);   // inf
    printf("safe length  = %e\n", safe);    // ~1.732e155


    return 0;
}