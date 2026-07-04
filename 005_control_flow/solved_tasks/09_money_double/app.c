#include <stdio.h>

int main()
{
  const double inflation = 5.0;

  double principal, rate;
  double balance, real;
  int year;

  printf("Enter principal and annual rate (%%): ");
  if (scanf("%lf%lf", &principal, &rate) != 2 || principal <= 0) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  printf("Absolute value:\n");
  balance = principal;
  year = 0;
  while (balance < 2 * principal) {
    year++;
    balance *= 1 + rate / 100;
    printf("Year %2d: %.2f", year, balance);
    if (balance >= 2 * principal) {
      printf("  ← doubled!");
    }
    printf("\n");
  }

  printf("\nReal value with infliation (%.0f%%):\n", inflation);
  if (rate <= inflation) {
    printf("Rate is lower than inflation. Your money is gone.\n");
    return 0;
  }

  real = principal;
  year = 0;
  while (real < 2 * principal) {
    year++;
    real *= (1 + rate / 100) / (1 + inflation / 100);
    printf("Year %2d: %.2f", year, real);
    if (real >= 2 * principal) {
      printf("  ← doubled!");
    }
    printf("\n");
  }

  return 0;
}
