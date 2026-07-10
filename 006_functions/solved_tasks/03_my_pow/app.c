#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(double* base, int* exp)
{
  printf("Enter base and exp: ");
  if (scanf("%lf %d", base, exp) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*base == 0.0 && *exp < 0) {
    fprintf(stderr, "devise by zero!\n");
    exit(1);
  }
  if (*exp == INT_MIN) {
    fprintf(stderr, "INT MIN\n");
    exit(2);
  }
}

double my_pow(double base, int exp)
{
  // Предусловие: 0 в отрицательной степени = деление на ноль
  assert(!(base == 0.0 && exp < 0));
  assert(exp != INT_MIN);

  int n = abs(exp);
  double result = 1.0;

  for (int i = 0; i < n; i++) {
    result *= base;
  }

  if (exp < 0) {
    result = 1.0 / result;
  }

  if (base > 0.0) {
    assert(result >= 0.0);
  } else if (base < 0) {
    assert(n % 2 ? result <= 0.0 : result >= 0.0);
  } else {
    assert(n == 0 ? result == 1.0 : result == 0.0);
  }

  return result;
}

int main()
{
  double base;
  int exp;

  read_input(&base, &exp);

  printf("\n%lf^%d = %f\n", base, exp, my_pow(base, exp));

  return 0;
}
