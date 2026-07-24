#include "algo.h"

// ---- Реализация расширенного алгоритма Евклида ----

// Итеративная версия.
//
// Ведём три пары чисел одновременно:
//   old_r, r — остатки (как в обычном алгоритме Евклида);
//   old_s, s — коэффициент при a;
//   old_t, t — коэффициент при b.
//
// Инвариант, который держится на каждом шаге:
//   old_s * a + old_t * b == old_r
//        s * a +      t * b ==      r
// Когда r обнуляется, old_r и есть НОД, а old_s, old_t — искомые x и y.
long long gcd_ext(long long a, long long b, long long *x, long long *y)
{
  long long old_r = a, r = b;
  long long old_s = 1, s = 0;
  long long old_t = 0, t = 1;

  while (r != 0) {
    long long q = old_r / r;  // частное — на сколько «укладывается» r в old_r
    long long tmp;

    tmp = old_r - q * r;  old_r = r;  r = tmp;  // остатки
    tmp = old_s - q * s;  old_s = s;  s = tmp;  // коэффициент при a
    tmp = old_t - q * t;  old_t = t;  t = tmp;  // коэффициент при b
  }

  // НОД по договорённости неотрицательный. Если получился со знаком минус
  // (это бывает при отрицательных входах) — меняем знак у всей тройки сразу,
  // тогда равенство a*x + b*y = g сохраняется.
  if (old_r < 0) {
    old_r = -old_r;
    old_s = -old_s;
    old_t = -old_t;
  }

  *x = old_s;
  *y = old_t;
  return old_r;
}

// Рекурсивная версия.
//
// База: gcd_ext_rec(a, 0) = a, при этом a*1 + 0*0 = a, значит x = 1, y = 0.
// Шаг: пусть для (b, a mod b) уже найдены x1, y1, то есть
//        b*x1 + (a mod b)*y1 = g.
// Подставим a mod b = a − (a/b)*b и сгруппируем — получим формулы:
//        x = y1,   y = x1 − (a/b)*y1.
long long gcd_ext_rec(long long a, long long b, long long *x, long long *y)
{
  if (b == 0) {
    if (a < 0) {  // держим НОД неотрицательным
      *x = -1;
      *y = 0;
      return -a;
    }
    *x = 1;
    *y = 0;
    return a;
  }

  long long x1, y1;
  long long g = gcd_ext_rec(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return g;
}
