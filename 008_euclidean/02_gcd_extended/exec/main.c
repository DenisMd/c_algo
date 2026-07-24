#include <stdio.h>

#include "algo.h"

// Ввод двух чисел с клавиатуры и печать результата.
// Вся математика — в модуле algo, здесь только общение с пользователем.

int main(void)
{
  long long a, b, x, y;

  printf("Enter 2 integers: ");
  if (scanf("%lld %lld", &a, &b) != 2) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  long long g = gcd_ext(a, b, &x, &y);

  printf("gcd(%lld, %lld) = %lld\n", a, b, g);
  // Соотношение Безу: a*x + b*y = g.
  printf("%lld * (%lld) + %lld * (%lld) = %lld\n", a, x, b, y, g);

  return 0;
}
