#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num = 15;

    bool interval_a = num > 15; // (15;+inf]
    bool interval_b = num >= 15; // [15;+inf]
    bool interval_c = num > 5 && num < 15; // (5;15)
    bool interval_d = num >= 5 && num <= 15; // [5;15]

    return 0;
}