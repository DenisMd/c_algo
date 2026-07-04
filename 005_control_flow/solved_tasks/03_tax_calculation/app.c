#include <stdio.h>

enum {
  EMPLOYEE = 1,
  SELF_EMPLOYED = 2,
  INDIVIDUAL_ENTREPRENEUR = 3
};

int main()
{
  const double deduction_per_child = 2000.0;
  const double deduction_income_limit = 80000.0;

  const double employee_limit_1 = 10000.0;
  const double employee_limit_2 = 50000.0;
  const double employee_rate_1 = 0.10;
  const double employee_rate_2 = 0.15;
  const double employee_rate_3 = 0.20;

  const double self_employed_limit = 20000.0;
  const double self_employed_rate_low = 0.05;
  const double self_employed_rate_high = 0.12;

  const double entrepreneur_fixed_tax = 6000.0;
  const double entrepreneur_limit = 100000.0;
  const double entrepreneur_rate = 0.06;

  double income, tax_base, tax;
  int category, children;

  printf("Enter income, category and children count: ");
  if (scanf("%lf%d%d", &income, &category, &children) != 3) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  if (income > deduction_income_limit) {
    tax_base = income;
  } else {
    tax_base = income - deduction_per_child * children;
    if (tax_base < 0) {
      tax_base = 0;
    }
  }

  switch (category) {
    case EMPLOYEE:
      if (tax_base <= employee_limit_1) {
        tax = tax_base * employee_rate_1;
      } else if (tax_base <= employee_limit_2) {
        tax = employee_limit_1 * employee_rate_2;
      } else {
        tax = employee_limit_1 * employee_rate_3;
      }
      break;
    case SELF_EMPLOYED:
      if (tax_base <= self_employed_limit) {
        tax = tax_base * self_employed_rate_low;
      } else {
        tax = tax_base * self_employed_rate_high;
      }
      break;
    case INDIVIDUAL_ENTREPRENEUR:
      if (tax_base <= entrepreneur_limit) {
        tax = entrepreneur_fixed_tax;
      } else {
        tax = tax_base * entrepreneur_rate;
        if (tax < entrepreneur_fixed_tax) {
          tax = entrepreneur_fixed_tax;
        }
      }
      break;
    default:
      fprintf(stderr, "Incorrect category!\n");
      return 2;
  }

  printf("%.2f\n", tax);

  return 0;
}
