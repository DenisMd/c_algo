#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_STEPS 20000

void read_input(double x[], size_t *n, size_t *steps, double *dt)
{
    printf("Enter n: ");
    if (scanf("%zu", n) != 1) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*n < 3 || *n > MAX_N) {
        fprintf(stderr, "Need 3..%d masses!\n", MAX_N);
        exit(1);
    }
    for (size_t i = 0; i < *n; i++) {
        if (scanf("%lf", &x[i]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            exit(1);
        }
    }
    if (scanf("%zu %lf", steps, dt) != 2) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }
    if (*steps < 1 || *steps > MAX_STEPS) {
        fprintf(stderr, "Need 1..%d steps!\n", MAX_STEPS);
        exit(1);
    }
    if (*dt <= 0.0) {
        fprintf(stderr, "Need dt > 0!\n");
        exit(1);
    }
}

void simulate(double x[], double x_prev[], size_t n, size_t steps, double dt, double log[])
{
    // TODO: steps шагов Верле. на каждом шаге:
    //   1) для внутренних i=1..n-2: x_new[i] = 2*x[i] - x_prev[i] + a*dt*dt,
    //      где a = x[i-1] + x[i+1] - 2*x[i]; концы копируются без изменений;
    //   2) сдвинуть: x_prev <- x, x <- x_new (через временный массив!);
    //   3) log[s] = x[n/2].
}

int main()
{
    double x[MAX_N];
    double x_prev[MAX_N];
    size_t n, steps;
    double dt;

    read_input(x, &n, &steps, &dt);

    for (size_t i = 0; i < n; i++) {
        x_prev[i] = x[i]; // старт из покоя: скорость = 0
    }

    double log[MAX_STEPS] = {0};
    simulate(x, x_prev, n, steps, dt, log);

    for (size_t s = 0; s < steps; s++) {
        printf("%.6f\n", log[s]);
    }

    return 0;
}
