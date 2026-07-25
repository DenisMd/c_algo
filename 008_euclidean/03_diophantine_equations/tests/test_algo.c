#include <stdio.h>
#include <stdlib.h>

#include "algo.h"
#include "testsuite.h"

// ---- Тесты линейного диофантова уравнения a*x + b*y = c ----
// Запуск: make test

typedef long long ll;

// Разрешимое уравнение: ждём ok == 1, а коэффициенты обязаны удовлетворять
// самому уравнению a*x + b*y == c. Произведение a*x может не влезть в
// long long, поэтому проверку считаем в __int128.
void check_solvable(ll a, ll b, ll c)
{
  ll x, y;
  int ok = solve_diophantine(a, b, c, &x, &y);
  printf("%lld*x + %lld*y = %lld  ->  x = %lld, y = %lld (ok = %d)\n", a, b, c,
         x, y, ok);

  TS_ASSERT(ok == 1);
  __int128 lhs = (__int128)a * x + (__int128)b * y;
  TS_ASSERT(lhs == (__int128)c);
}

// Неразрешимое уравнение: ждём, что функция вернёт 0.
void check_unsolvable(ll a, ll b, ll c)
{
  ll x, y;
  int ok = solve_diophantine(a, b, c, &x, &y);
  printf("%lld*x + %lld*y = %lld  ->  нет решений (ok = %d)\n", a, b, c, ok);

  TS_ASSERT(ok == 0);
}

int main(void)
{
  // TS_CONTINUE — увидеть сразу все провалы.
  // Поменяйте на TS_FAIL_FAST, чтобы прогон падал на первой ошибке.
  ts_set_mode(TS_CONTINUE);

  ts_begin("есть решение: gcd(a, b) делит c");
  check_solvable(6, 15, 9);      // g = 3 делит 9
  check_solvable(2, 3, 5);       // взаимно простые: решается для любого c
  check_solvable(12, 8, 4);      // g = 4 делит 4
  check_solvable(12, 8, 20);     // g = 4 делит 20
  check_solvable(1071, 462, 21);  // классический пример, g = 21
  check_solvable(-6, 15, 9);     // знак коэффициентов не мешает
  check_solvable(6, -15, -9);
  check_solvable(7, 0, 14);      // b = 0: уравнение 7x = 14
  check_solvable(0, 5, 10);      // a = 0: уравнение 5y = 10
  check_solvable(0, 0, 0);       // 0 = 0 — подходит любая пара

  ts_begin("нет решения: gcd(a, b) не делит c");
  check_unsolvable(6, 15, 10);  // g = 3 не делит 10
  check_unsolvable(2, 4, 3);    // g = 2 не делит 3
  check_unsolvable(12, 8, 5);   // g = 4 не делит 5
  check_unsolvable(7, 0, 10);   // 7x = 10 — нет целого x
  check_unsolvable(0, 0, 7);    // 0 = 7 — невозможно

  ts_begin("большие числа");
  check_solvable(123456789012LL, 987654321098LL, 2);  // g = 2 делит 2
  check_solvable(1000000007LL * 3, 1000000007LL * 5, 1000000007LL * 4);

  return ts_summary();
}
