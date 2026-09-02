#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(double* start, double* stop, size_t* n)
{
  printf("Enter start stop n: ");
  if (scanf("%lf %lf %zu", start, stop, n) != 3) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

void print_array(const double a[], size_t n)
{
  for (size_t i = 0; i < n; i++) {
    printf("%g", a[i]);
    if (i + 1 < n) {
      printf(" ");
    }
  }
  printf("\n");
}

double* linspace(double start, double stop, size_t n)
{
  if (n == 0) {
    return NULL; // нечего выделять
  }

  double* a = malloc(n * sizeof(double));
  if (a == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  double step = (n > 1) ? (stop - start) / (double)(n - 1) : 0.0;

  for (size_t i = 0; i < n; i++) {
    a[i] = start + (double)i * step; // не x += step: ошибка округления копилась бы
  }

  if (n > 1) {
    a[n - 1] = stop; // край ровно stop, без ошибки округления
  }

  return a;
}

int main()
{
  double start, stop;
  size_t n;

  read_input(&start, &stop, &n);

  double* a = linspace(start, stop, n);
  if (a == NULL && n > 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }
  assert(n == 0 || a[0] == start); // края точные по построению

  print_array(a, n);

  free(a);
  a = NULL;

  return 0;
}
