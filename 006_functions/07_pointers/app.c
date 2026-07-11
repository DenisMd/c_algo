#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef VERBOSE
#define VERBOSE 0
#endif

// Печатает рост вклада по годам и ВОЗВРАЩАЕТ год, когда сумма удвоилась.
int years_to_double(double principal, double rate)
{
  double balance = principal;
  int year = 0;
  assert(balance >= 0.0);
  assert(rate >= 0.0 && rate <= 100.0);
  while (balance < 2 * principal) {
    year++;
    balance *= 1 + rate / 100;
    if (VERBOSE) {
      printf("Year %2d: %.2f\n", year, balance);
    }
  }
  return year;
}

bool read_input(double* principal, double* rate)
{
  printf("Enter principal and annual rate (%%): ");
  if (scanf("%lf%lf", principal, rate) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    return false;
  }
  if (*principal <= 0.0) {
    fprintf(stderr, "Principal must be positive!\n");
    return false;
  }
  if (*rate <= 0.0 || *rate > 100.0) {
    fprintf(stderr, "Rate must be positive!\n");
    return false;
  }
  return true;
}

void read_input_2(double* principal, double* rate)
{
  printf("Enter principal and annual rate (%%): ");
  if (scanf("%lf%lf", principal, rate) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
  if (*principal <= 0.0) {
    fprintf(stderr, "Principal must be positive!\n");
    exit(1);
  }
  if (*rate <= 0.0 || *rate > 100.0) {
    fprintf(stderr, "Rate must be positive!\n");
    exit(1);
  }
}

int main()
{
  double principal, rate;

  if (!read_input(&principal, &rate)) {
    return 1;
  }

  int year = years_to_double(principal, rate);
  printf("Doubled in %d years!\n", year);

  return 0;
}
