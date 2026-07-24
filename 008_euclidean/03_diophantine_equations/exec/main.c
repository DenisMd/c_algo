#include <stdio.h>

#include "algo.h"

// Ввод коэффициентов a, b, c и печать решения уравнения a*x + b*y = c.
// Вся математика — в модуле algo, здесь только общение с пользователем.

int main(void)
{
  long long a, b, c, x, y;

  printf("Enter a, b, c for a*x + b*y = c: ");
  if (scanf("%lld %lld %lld", &a, &b, &c) != 3) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  if (solve_diophantine(a, b, c, &x, &y)) {
    printf("x = %lld, y = %lld\n", x, y);
    printf("%lld * (%lld) + %lld * (%lld) = %lld\n", a, x, b, y, c);
  } else {
    printf("no integer solutions\n");
  }

  return 0;
}
