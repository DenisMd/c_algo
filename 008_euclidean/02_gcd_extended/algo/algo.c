#include "algo.h"
#include <assert.h>
#include <limits.h>

// LLONG_MIN нельзя брать со знаком минус (переполнение), а расширенному
// алгоритму приходится менять знаки. Поэтому такой вход запрещаем.

long long gcd_ext(long long a, long long b, long long *x, long long *y)
{
  assert(a != LLONG_MIN);
  assert(b != LLONG_MIN);
  // TODO:
  *x = 0;
  *y = 0;
  return 0;
}

long long gcd_ext_rec(long long a, long long b, long long *x, long long *y)
{
  assert(a != LLONG_MIN);
  assert(b != LLONG_MIN);
  // TODO:
  *x = 0;
  *y = 0;
  return 0;
}
