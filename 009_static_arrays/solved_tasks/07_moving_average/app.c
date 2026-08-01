#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(double price[], size_t* n, size_t* w)
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
    if (scanf("%lf", &price[i]) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
  }
  if (scanf("%zu", w) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*w < 1 || *w > *n) {
    fprintf(stderr, "Need 1 <= w <= n!\n");
    exit(1);
  }
}

void moving_average(const double price[], size_t n, size_t w, double sma[])
{
  double sum = 0.0;
  for (size_t i = 0; i < n; i++) {
    sum += price[i];
    if (i >= w) {
      sum -= price[i - w]; // элемент вышел из окна
    }
    // окно заполнилось начиная с i = w-1; раньше SMA не определена
    sma[i] = (i >= w - 1) ? sum / (double)w : NAN;
  }
}

size_t golden_crosses(const double price[], const double sma[], size_t n, size_t w, size_t days[])
{
  size_t cnt = 0;
  // с i = w обе величины sma[i-1] и sma[i] уже определены
  for (size_t i = w; i < n; i++) {
    if (price[i - 1] < sma[i - 1] && price[i] > sma[i]) {
      days[cnt++] = i;
    }
  }
  return cnt;
}

int main()
{
  double price[MAX_N];
  size_t n, w;

  read_input(price, &n, &w);
  assert(w >= 1 && w <= n);

  double sma[MAX_N];
  moving_average(price, n, w, sma);

  size_t days[MAX_N];
  size_t cnt = golden_crosses(price, sma, n, w, days);

  printf("%zu\n", cnt);
  for (size_t i = 0; i < cnt; i++) {
    printf("%zu%s", days[i], (i + 1 < cnt) ? " " : "");
  }
  printf("\n");

  return 0;
}
