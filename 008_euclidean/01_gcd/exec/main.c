#include <stdio.h>

#include "algo.h"

// Ввод двух чисел с клавиатуры и печать результата.
// Вся математика — в модуле algo, здесь только общение с пользователем.

int main(void)
{
  long long a, b;

  printf("Enter 2 integers: ");
  if (scanf("%lld %lld", &a, &b) != 2) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  printf("gcd(%lld, %lld) = %lld\n", a, b, gcd(a, b));

  return 0;
}
