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
  if (*n > MAX_N) {
    fprintf(stderr, "Too many elements (max %d)!\n", MAX_N);
    exit(1);
  }
  for (size_t i = 0; i < *n; i++) {
    if (scanf("%d", &a[i]) != 1 || a[i] < 0) {
      fprintf(stderr, "Incorrect input (need non-negative)!\n");
      exit(1);
    }
  }
}

void print_histogram(const int count[10])
{
  for (int d = 0; d < 10; d++) {
    printf("%d: %d\n", d, count[d]);
  }
}

void digit_histogram(const int a[], size_t n, int count[10])
{
  for (int d = 0; d < 10; d++) {
    count[d] = 0;
  }

  for (size_t i = 0; i < n; i++) {
    int x = a[i]; // x >= 0
    if (x == 0) {
      count[0]++; // отдельный случай: у нуля одна цифра 0
      continue;
    }
    while (x > 0) {
      count[x % 10]++; // последняя цифра
      x /= 10;         // отбрасываем её
    }
  }
}

int main()
{
  int a[MAX_N];
  size_t n;

  read_input(a, &n);
  assert(n <= MAX_N);

  int count[10];
  digit_histogram(a, n, count);

  print_histogram(count);

  return 0;
}
