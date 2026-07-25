#include <stdio.h>
#include <stdlib.h>

#include "algo.h"
#include "testsuite.h"

// ---- Тесты расширенного алгоритма Евклида ----
// Запуск: make test

typedef long long ll;
typedef ll (*gcd_ext_callback)(ll, ll, ll *, ll *);

// Одна проверка = несколько утверждений:
//   1) НОД совпал с ожидаемым;
//   2) выполнено соотношение Безу: a*x + b*y == g;
//   3) найденный НОД делит a и делит b.
// Пункт 2 — суть расширенного алгоритма: он ловит случай, когда g угадан
// верно, но коэффициенты x, y неправильные.
void check(gcd_ext_callback gcd_ext_call, ll a, ll b, ll expected)
{
  ll x, y;
  ll g = gcd_ext_call(a, b, &x, &y);
  printf("gcd_ext(%lld, %lld) = %lld,  x = %lld, y = %lld\n", a, b, g, x, y);

  TS_ASSERT_INT(g, expected);

  // Произведение a*x может не влезть в long long, поэтому считаем в __int128.
  __int128 bezout = (__int128)a * x + (__int128)b * y;
  TS_ASSERT(bezout == (__int128)g);

  // gcd(0, 0) == 0 — единственный случай, когда делить нельзя (%0 это UB).
  if (g == 0) {
    return;
  }
  TS_ASSERT(a % g == 0);
  TS_ASSERT(b % g == 0);
}

int main(void)
{
  // TS_CONTINUE — увидеть сразу все провалы.
  // Поменяйте на TS_FAIL_FAST, чтобы прогон падал на первой ошибке.
  ts_set_mode(TS_CONTINUE);

  gcd_ext_callback gcd_ext_call = NULL;

  for (int i = 0; i < 2; i++) {
    if (i == 1) {
      gcd_ext_call = gcd_ext;
      printf(
          "\n\n----------------- GCD_EXT через цикл ------------------\n\n");
    } else {
      gcd_ext_call = gcd_ext_rec;
      printf(
          "\n\n--------------- GCD_EXT через рекурсию ----------------\n\n");
    }

    ts_begin("gcd_ext — базовые случаи");
    check(gcd_ext_call, 12, 8, 4);
    check(gcd_ext_call, 8, 12, 4);     // порядок не важен
    check(gcd_ext_call, 17, 5, 1);     // взаимно простые
    check(gcd_ext_call, 100, 25, 25);  // одно делит другое
    check(gcd_ext_call, 7, 7, 7);
    check(gcd_ext_call, 0, 5, 5);  // gcd_ext(0, x) == x
    check(gcd_ext_call, 5, 0, 5);
    check(gcd_ext_call, 0, 0, 0);    // соглашение
    check(gcd_ext_call, -12, 8, 4);  // знак не влияет на НОД
    check(gcd_ext_call, 12, -8, 4);
    check(gcd_ext_call, -12, -8, 4);
    check(gcd_ext_call, 1071, 462, 21);  // классический пример из учебников

    // ---- Числа Фибоначчи: худший случай алгоритма ----
    // Соседние числа Фибоначчи взаимно просты, а деление всегда даёт частное 1
    // — алгоритм делает максимально возможное число шагов (теорема Ламе).
    ts_begin("Фибоначчи — соседние взаимно просты");
    check(gcd_ext_call, 5, 8, 1);
    check(gcd_ext_call, 13, 21, 1);
    check(gcd_ext_call, 55, 89, 1);
    check(gcd_ext_call, 610, 987, 1);
    check(gcd_ext_call, 75025, 121393, 1);  // F(25), F(26)

    ts_begin("большие числа");
    check(gcd_ext_call, 123456789012LL, 987654321098LL, 2);
    check(gcd_ext_call, 1000000007LL * 3, 1000000007LL * 5, 1000000007LL);
  }
  return ts_summary();
}
