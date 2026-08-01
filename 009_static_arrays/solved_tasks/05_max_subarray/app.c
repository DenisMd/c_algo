#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

void read_input(int a[], size_t* n)
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
    if (scanf("%d", &a[i]) != 1) {
      fprintf(stderr, "Incorrect input!\n");
      exit(1);
    }
  }
}

long max_subarray(const int a[], size_t n)
{
  long best = a[0]; // старт с a[0], НЕ с 0 — иначе для всех отрицательных ошибка
  long cur = a[0];  // лучшая сумма подотрезка, оканчивающегося на текущем элементе

  for (size_t i = 1; i < n; i++) {
    // тянуть неположительный хвост невыгодно — тогда начинаем заново с a[i]
    cur = (cur > 0) ? cur + a[i] : a[i];
    if (cur > best) {
      best = cur;
    }
  }
  return best;
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n >= 1); // подотрезок непустой

  printf("%ld\n", max_subarray(a, n));

  return 0;
}
