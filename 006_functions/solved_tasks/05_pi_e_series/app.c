#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_input(int *n)
{
  printf("Enter number of terms N: ");
  if (scanf("%d", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*n < 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

double my_e(int terms)
{
  double sum = 0.0;
  double term = 1.0;  // 1/0! = 1

  for (int i = 0; i < terms; i++) {
    sum += term;
    term /= (i + 1);  // следующее слагаемое: делим на (i + 1)
  }

  return sum;
}

double my_pi_leibniz(int terms)
{
  double sum = 0.0;

  for (int i = 0; i < terms; i++) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0;
    sum += sign / (2 * i + 1);
  }

  return 4.0 * sum;
}

int main()
{
  int n;

  read_input(&n);

  double e = my_e(n);
  double pi = my_pi_leibniz(n);

  printf("e  ≈ %.15f  (истинное %.15f, ошибка %.2e)\n", e, M_E, fabs(e - M_E));
  printf("pi ≈ %.15f  (истинное %.15f, ошибка %.2e)\n", pi, M_PI, fabs(pi - M_PI));

  return 0;
}
