#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BOUNCE 0.8 // доля скорости, остающаяся после удара о пол

void read_size(size_t* n)
{
  printf("Enter n: ");
  if (scanf("%zu", n) != 1 || *n < 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

void read_particles(double x[], double v[], size_t n)
{
  for (size_t i = 0; i < n; i++) {
    if (scanf("%lf %lf", &x[i], &v[i]) != 2) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
    if (x[i] < 0.0) {
      fprintf(stderr, "Particle must start above the floor!\n");
      exit(1);
    }
  }
}

void read_steps(size_t* steps, double* dt, double* g)
{
  if (scanf("%zu %lf %lf", steps, dt, g) != 3) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

void print_array(const double a[], size_t n)
{
  for (size_t i = 0; i < n; i++) {
    printf("%.4f", a[i]);
    if (i + 1 < n) {
      printf(" ");
    }
  }
  printf("\n");
}

void step_euler(double* x, double* v, size_t n, double dt, double g)
{
  for (size_t i = 0; i < n; i++) {
    v[i] += g * dt;    // сначала обновляем скорость
    x[i] += v[i] * dt; // и уже новой скоростью двигаем частицу

    if (x[i] < 0.0) {
      x[i] = -x[i];          // ушли под пол — отражаем обратно
      v[i] = -BOUNCE * v[i]; // и разворачиваем скорость, часть её теряется в ударе
    }
  }
}

int main()
{
  size_t n;
  read_size(&n);

  // n известно только сейчас, во время выполнения — массивы берём из кучи
  double* x = malloc(n * sizeof(double));
  double* v = malloc(n * sizeof(double));
  if (x == NULL || v == NULL) {
    free(x); // вторая аллокация могла упасть — первую нельзя терять
    free(v);
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  read_particles(x, v, n);

  size_t steps;
  double dt, g;
  read_steps(&steps, &dt, &g);

  for (size_t s = 0; s < steps; s++) {
    step_euler(x, v, n, dt, g);
  }

  for (size_t i = 0; i < n; i++) {
    assert(x[i] >= 0.0); // после отражения ни одна частица не остаётся под полом
  }

  print_array(x, n);
  print_array(v, n);

  free(x);
  free(v);
  x = NULL;
  v = NULL;

  return 0;
}
