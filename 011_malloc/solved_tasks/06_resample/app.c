#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

void read_input(double a[], size_t* n, size_t* m)
{
  printf("Enter n, a, m: ");
  if (scanf("%zu", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*n > MAX_N) {
    fprintf(stderr, "Too many elements (max %d)!\n", MAX_N);
    exit(1);
  }
  for (size_t i = 0; i < *n; i++) {
    if (scanf("%lf", &a[i]) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
  }
  if (scanf("%zu", m) != 1) {
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

double* resample(const double* a, size_t n, size_t m)
{
  if (n == 0 || m == 0) {
    return NULL; // не из чего или не во что интерполировать
  }

  double* res = malloc(m * sizeof(double));
  if (res == NULL) {
    return NULL; // память не дали — решает вызывающий
  }

  if (n == 1 || m == 1) {
    for (size_t j = 0; j < m; j++) {
      res[j] = a[0]; // интерполировать нечем: одна точка
    }
    return res;
  }

  for (size_t j = 0; j < m; j++) {
    // куда попадает j-й выходной отсчёт на исходной сетке 0 .. n-1
    double pos = (double)j * (double)(n - 1) / (double)(m - 1);
    size_t i = (size_t)pos;

    if (i + 1 >= n) {
      res[j] = a[n - 1]; // правый край: соседа справа нет, читать a[i+1] нельзя
    } else {
      double frac = pos - (double)i;
      res[j] = a[i] + frac * (a[i + 1] - a[i]);
    }
  }

  return res;
}

int main()
{
  double a[MAX_N];
  size_t n, m;

  read_input(a, &n, &m);
  assert(n <= MAX_N); // read_input это гарантирует

  double* res = resample(a, n, m);
  if (res == NULL && n > 0 && m > 0) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }
  // при m == n сетки совпадают, frac всюду 0 — должна получиться точная копия
  assert(m != n || n == 0 || memcmp(res, a, n * sizeof(double)) == 0);

  size_t len = (n == 0) ? 0 : m; // из пустого входа интерполировать нечего
  print_array(res, len);

  free(res);
  res = NULL;

  return 0;
}
