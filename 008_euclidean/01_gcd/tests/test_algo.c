#include <stdio.h>
#include <stdlib.h>

#include "algo.h"
#include "testsuite.h"

// ---- Тесты алгоритма Евклида ----
// Запуск: make test

typedef long long ll;
typedef ll (*gcd_callback)(ll, ll);

// n-е число Фибоначчи: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2).
// В long long помещается до F(92); F(93) уже переполняет тип.
ll fib(int n)
{
  ll prev = 0, cur = 1;
  for (int i = 0; i < n; i++) {
    ll next = prev + cur;
    prev = cur;
    cur = next;
  }
  return prev;  // после цикла prev == F(n)
}

// Сколько шагов (делений с остатком) делает алгоритм Евклида для (a, b).
// Это ровно столько же, сколько раз рекурсивный gcd_rec вызывает сам себя.
// Считаем отдельной функцией, чтобы не трогать сам алгоритм в algo.c.
int gcd_steps(ll a, ll b)
{
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;

  int steps = 0;
  while (b != 0) {
    ll r = a % b;
    a = b;
    b = r;
    steps++;
  }
  return steps;
}

// Одна проверка = три утверждения:
//   1) ответ совпал с ожидаемым;
//   2) найденное число делит a;
//   3) найденное число делит b.
// Пункты 2-3 ловят случай, когда функция вернула правдоподобное, но неверное
// число: настоящий делитель обязан делить оба аргумента без остатка.
void check(gcd_callback gcd_call, ll a, ll b, ll expected)
{
  printf("gdc(%lld, %lld) = %lld\n",a,b,expected);
  ll gcd = gcd_call(a, b);
  TS_ASSERT_INT(gcd, expected);

  // gcd(0, 0) == 0 — единственный случай, когда делить нельзя (%0 это UB).
  if (gcd == 0) {
    return;
  }
  TS_ASSERT(a % gcd == 0);
  TS_ASSERT(b % gcd == 0);
}

int main(void)
{
  // TS_CONTINUE — увидеть сразу все провалы.
  // Поменяйте на TS_FAIL_FAST, чтобы прогон падал на первой ошибке.
  ts_set_mode(TS_CONTINUE);

  // ---- Сколько раз работает алгоритм Евклида ----
  // Соседние числа Фибоначчи — худший случай (теорема Ламе): деление всегда
  // даёт частное 1, поэтому шагов максимум. Видно, что числа растут
  // экспоненциально, а число шагов — всего лишь линейно по n.
  printf("== Число шагов Евклида на соседних Фибоначчи ==\n");
  for (int n = 10; n <= 90; n += 10) {
    ll a = fib(n + 1);
    ll b = fib(n);
    printf("gcd(F(%2d), F(%2d)) = gcd(%19lld, %19lld): %2d шагов\n", n + 1, n, a,
           b, gcd_steps(a, b));
  }

  // Что именно тестируем. Поменяйте на gcd_rec — тесты те же.
  gcd_callback gcd_call = NULL;

  for (int i = 0; i < 2; i++) {
    if (i == 1) {
      gcd_call = gcd;
      printf(
          "\n\n-------------------- GCD через цикл --------------------\n\n");
    } else {
      gcd_call = gcd_rec;
      printf(
          "\n\n-------------------- GCD через рекурсию "
          "--------------------\n\n");
    }

    ts_begin("gcd — базовые случаи");
    check(gcd_call, 12, 8, 4);
    check(gcd_call, 8, 12, 4);     // порядок не важен
    check(gcd_call, 17, 5, 1);     // взаимно простые
    check(gcd_call, 100, 25, 25);  // одно делит другое
    check(gcd_call, 7, 7, 7);
    check(gcd_call, 0, 5, 5);  // gcd_call(0, x) == x
    check(gcd_call, 5, 0, 5);
    check(gcd_call, 0, 0, 0);    // соглашение
    check(gcd_call, -12, 8, 4);  // знак не влияет
    check(gcd_call, 12, -8, 4);  // знак не влияет
    check(gcd_call, -12, -8, 4);
    check(gcd_call, 1071, 462, 21);  // классический пример из учебников

    // ---- Числа Фибоначчи: худший случай алгоритма ----
    // 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
    // Соседние числа Фибоначчи взаимно просты, а деление всегда даёт
    // частное 1 — то есть алгоритм отнимает по минимуму и делает
    // максимально возможное число шагов. Это теорема Ламе.
    ts_begin("Фибоначчи — соседние взаимно просты");
    check(gcd_call, 5, 8, 1);
    check(gcd_call, 13, 21, 1);
    check(gcd_call, 55, 89, 1);
    check(gcd_call, 610, 987, 1);
    check(gcd_call, 75025, 121393, 1);  // F(25), F(26)

    ts_begin("Фибоначчи — gcd(F(m), F(n)) == F(gcd(m, n))");
    check(gcd_call, 21, 34, 1);       // F(8),  F(9)  -> F(1) = 1
    check(gcd_call, 8, 34, 2);        // F(6),  F(9)  -> F(3) = 2
    check(gcd_call, 144, 233, 1);     // F(12), F(13) -> F(1) = 1
    check(gcd_call, 144, 610, 2);     // F(12), F(15) -> F(3) = 2
    check(gcd_call, 6765, 46368, 3);  // F(20), F(24) -> F(4) = 3

    // Самые большие соседние Фибоначчи, влезающие в long long (до F(92)).
    // Соседние взаимно просты, поэтому НОД == 1 — но алгоритм добирается до
    // него за максимальное число шагов.
    ts_begin("Фибоначчи — большие, через fib()");
    check(gcd_call, fib(46), fib(45), 1);
    check(gcd_call, fib(70), fib(69), 1);
    check(gcd_call, fib(92), fib(91), 1);

    ts_begin("большие числа");
    check(gcd_call, 123456789012LL, 987654321098LL, 2);
    check(gcd_call, 1000000007LL * 3, 1000000007LL * 5, 1000000007LL);
  }
  return ts_summary();
}
