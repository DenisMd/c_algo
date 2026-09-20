#include "fraction.h"

#include <stdio.h>

static int gcd(int a, int b)  // алгоритм Евклида, урок 008
{
  if (a < 0) a = -a;
  if (b < 0) b = -b;

  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

struct fraction fraction_reduce(struct fraction f)
{
  if (f.den < 0) {  // минус держим в числителе
    f.num = -f.num;
    f.den = -f.den;
  }

  int d = gcd(f.num, f.den);  // gcd(0, den) == den, поэтому ноль даёт 0/1

  f.num /= d;
  f.den /= d;

  return f;
}

struct fraction fraction_add(struct fraction a, struct fraction b)
{
  struct fraction sum = {a.num * b.den + b.num * a.den, a.den * b.den};
  return fraction_reduce(sum);
}

struct fraction fraction_mul(struct fraction a, struct fraction b)
{
  struct fraction product = {a.num * b.num, a.den * b.den};
  return fraction_reduce(product);
}

void fraction_print(struct fraction f)
{
  if (f.den == 1) {
    printf("%d", f.num);
  } else {
    printf("%d/%d", f.num, f.den);
  }
}
