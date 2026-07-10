#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-9

// Максимум итераций: страховка от бесконечного цикла, если метод не сходится
const int MAX_ITER = 1000;

void read_input(double *x)
{
  printf("Enter x: ");
  if (scanf("%lf", x) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*x < 0.0) {
    fprintf(stderr, "Negative input!\n");
    exit(1);
  }
}

double my_sqrt(double x)
{
  // Предусловие: корень из отрицательного не определён в вещественных числах
  assert(x >= 0.0);

  if (x == 0.0) {
    return 0.0;
  }

  double guess = x;
  double next = (guess + x / guess) / 2.0;
  int iter = 1;

  // Итерируем до сходимости: пока приближение ещё заметно меняется
  while (fabs(next - guess) >= EPSILON) {
    if (iter >= MAX_ITER) {
      fprintf(stderr, "No convergence!\n");
      exit(1);
    }
    guess = next;
    next = (guess + x / guess) / 2.0;
    iter++;
  }

  return next;
}

int main()
{
  double x;

  read_input(&x);

  printf("\nsqrt(%lf) = %f\n", x, my_sqrt(x));

  return 0;
}
