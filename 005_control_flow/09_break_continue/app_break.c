#include <math.h>  // для fabs()
#include <stdio.h>

/*
Мы хотим решить уравнение:
x² = a (или x² – a = 0).

Метод Ньютона для уравнения f(x) = 0 гласит:
xₙ₊₁ = xₙ – f(xₙ) / f'(xₙ).

В нашем случае:
f(x) = x² – a,
f'(x) = 2x.

Подставляем:
xₙ₊₁ = xₙ – (xₙ² – a) / (2xₙ) = xₙ – xₙ/2 + a/(2xₙ) = xₙ/2 + a/(2xₙ) = 0.5 * (xₙ
+ a/xₙ).
*/

int main()
{
  double a;
  printf("Enter num for sqrt: ");
  if (scanf("%lf", &a) != 1) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  if (a < 0) {
    printf("Negative number is not supported.\n");
    return 1;
  }

  double x = a;        // начальное приближение
  double eps = 1e-10;  // желаемая точность
  int max_iter = 100;  // защита от бесконечного цикла
  int iter = 0;

  printf("Iteration calculation sqrt(%g):\n", a);

  while (1) {
    double prev = x;
    x = 0.5 * (x + a / x);  // метод Ньютона
    iter++;

    // Проверка достижения точности
    if (fabs(x - prev) < eps) {
      printf("Sqrt is found for %d iteration.\n", iter);
      break;
    }

    // Проверка превышения лимита итераций
    if (iter >= max_iter) {
      printf("Limit of iteration is exceeded (%d). Current num: %.15f\n",
             max_iter, x);
      break;
    }

    // (опционально) печать промежуточных значений
    printf("Iteration %d: x = %.15f\n", iter, x);
  }

  printf("Result: sqrt(%g) ≈ %.15f\n", a, x);
  printf("Check in std sqrt(%g) = %.15f\n", a, sqrt(a));

  return 0;
}