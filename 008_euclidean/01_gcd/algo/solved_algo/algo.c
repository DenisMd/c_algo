#include "algo.h"

// ---- Реализация ----

// Остаток в C может быть отрицательным: -5 % 3 == -2 (см. examples/mod_negative.c).
// Поэтому берём модуль числа: НОД не зависит от знака.
long long abs_ll(long long x)
{
  return x < 0 ? -x : x;
}

long long gcd(long long a, long long b)
{
  a = abs_ll(a);
  b = abs_ll(b);

  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }

  // gcd(x, 0) == x, поэтому в конце ответ лежит в a.
  return a;
  
}

long long gcd_rec(long long a, long long b)
{
  a = abs_ll(a);
  b = abs_ll(b);

  if (b == 0) {
    return a;  // база рекурсии
  }
  return gcd_rec(b, a % b);
}
