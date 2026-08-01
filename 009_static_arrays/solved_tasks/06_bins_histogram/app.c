#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_B 1000

void read_input(double data[], size_t* n, size_t* b)
{
  printf("Enter n: ");
  if (scanf("%zu", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*n < 1 || *n > MAX_N) {
    fprintf(stderr, "Need 1..%d elements!\n", MAX_N);
    exit(1);
  }
  for (size_t i = 0; i < *n; i++) {
    if (scanf("%lf", &data[i]) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
  }
  if (scanf("%zu", b) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*b < 1 || *b > MAX_B) {
    fprintf(stderr, "Need 1..%d bins!\n", MAX_B);
    exit(1);
  }
}

void histogram(const double data[], size_t n, size_t b, int bins[])
{
  for (size_t k = 0; k < b; k++) {
    bins[k] = 0;
  }

  // границы находим сами: минимум и максимум данных
  double lo = data[0];
  double hi = data[0];
  for (size_t i = 1; i < n; i++) {
    if (data[i] < lo) {
      lo = data[i];
    }
    if (data[i] > hi) {
      hi = data[i];
    }
  }

  double width = (hi - lo) / (double)b; // ширина одной корзины

  for (size_t i = 0; i < n; i++) {
    size_t k;
    if (width == 0.0) {
      k = 0; // все значения одинаковы — делить нельзя, всё в первую корзину
    } else {
      // наивная формула даёт b, когда x == hi (или чуть больше из-за double),
      // поэтому загоняем индекс в последнюю корзину b-1.
      k = (size_t)((data[i] - lo) / width);
      if (k >= b) {
        k = b - 1;
      }
    }
    bins[k]++;
  }
}

int main()
{
  double data[MAX_N];
  size_t n, b;

  read_input(data, &n, &b);
  assert(n >= 1 && b >= 1);

  int bins[MAX_B];
  histogram(data, n, b, bins);

  for (size_t k = 0; k < b; k++) {
    printf("%zu: %d\n", k, bins[k]);
  }

  return 0;
}
