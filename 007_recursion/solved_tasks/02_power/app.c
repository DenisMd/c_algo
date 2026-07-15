#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(int* a, int* n)
{
  printf("Enter a and n: ");
  if (scanf("%d %d", a, n) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*n < 0) {
    fprintf(stderr, "negative exponent is not supported!\n");
    exit(1);
  }
}

long long power(int a, int n)
{
  // Предусловие: показатель неотрицательный
  assert(n >= 0);

  if (n == 0) {
    return 1;                      // база: a⁰ = 1
  }

  return (long long)a * power(a, n - 1); // шаг: aⁿ = a · aⁿ⁻¹
}

int main()
{
  int a, n;

  read_input(&a, &n);

  printf("%d^%d = %lld\n", a, n, power(a, n));

  return 0;
}
