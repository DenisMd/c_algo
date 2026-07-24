#include "algo.h"                            // свой заголовок: solve_diophantine
#include "../../02_gcd_extended/algo/algo.h"  // прошлый урок: gcd_ext

// ---- Решение линейного диофантова уравнения a*x + b*y = c ----
//
// Идея опирается на расширенный алгоритм Евклида из прошлого урока:
//   1) gcd_ext даёт g = gcd(a, b) и коэффициенты Безу x0, y0:
//          a*x0 + b*y0 = g;
//   2) уравнение разрешимо в целых числах <=> g делит c;
//   3) домножив равенство на c/g, получаем частное решение:
//          a*(x0 * c/g) + b*(y0 * c/g) = c.
//
// Общее решение (для справки, здесь не возвращается):
//   x = x0*(c/g) + k*(b/g),   y = y0*(c/g) - k*(a/g),   k — любое целое.

int solve_diophantine(long long a, long long b, long long c, long long *x,
                      long long *y)
{
  long long x0, y0;
  long long g = gcd_ext(a, b, &x0, &y0);  // вызов решения из прошлого урока

  // Особый случай a == b == 0: уравнение вырождается в 0 == c.
  if (g == 0) {
    if (c != 0) {
      return 0;  // 0 = c при c != 0 — решений нет
    }
    *x = 0;
    *y = 0;
    return 1;  // 0 = 0 — подходит любая пара, берём (0, 0)
  }

  if (c % g != 0) {
    return 0;  // g не делит c — целых решений нет
  }

  long long factor = c / g;
  *x = x0 * factor;
  *y = y0 * factor;
  return 1;
}
