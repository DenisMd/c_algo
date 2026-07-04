#include <stdio.h>

int main()
{
  double a, b, result;
  int choice;

  printf("Enter 2 numbers: ");
  if (scanf("%lf%lf", &a, &b) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;  // error code
  }

  printf("Choose opertaion:\n");
  printf("1 - add\n2 - sub\n3 - mult\n4 - div\n");
  if (scanf("%d", &choice) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;  // error code
  }

  switch (choice) {
    case 1:
      result = a + b;
      printf("%.2f + %.2f = %.2f\n", a, b, result);
      break;
    case 2:
      result = a - b;
      printf("%.2f - %.2f = %.2f\n", a, b, result);
      break;
    case 3:
      result = a * b;
      printf("%.2f * %.2f = %.2f\n", a, b, result);
      break;
    case 4:
      if (b == 0.0) {
        fprintf(stderr, "Devise by zero\n");
        return 2;  // error code
      }

      result = a / b;
      printf("%.2f / %.2f = %.2f\n", a, b, result);
      break;
    default:
      fprintf(stderr, "Incorrect operation\n");
      return 3;  // error code
  }

  return 0;
}