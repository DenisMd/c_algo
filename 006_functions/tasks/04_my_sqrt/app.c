#include <stdio.h>
#include <stdlib.h>

// Максимум итераций: страховка от бесконечного цикла, если метод не сходится
const int MAX_ITER = 1000;

void read_input(double *x)
{
    printf("Enter x: ");
    if (scanf("%lf", x) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*x < 0.0) {
        fprintf(stderr, "Negative input!\n");
        exit(1);
    }
}

double my_sqrt(double x)
{
    // TODO: метод Ньютона
    // g_next = (g + x / g) / 2
    // Итерировать, пока |g_next - g| >= EPSILON
    // Не забыть про x == 0
    // Если не сошлись за MAX_ITER шагов — exit(1)

    return 0;
}

int main()
{
    double x;

    read_input(&x);

    printf("%f\n", my_sqrt(x));

    return 0;
}
