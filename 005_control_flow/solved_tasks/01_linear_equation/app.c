#include <stdio.h>

int main()
{
  double a, b, x;
  printf("Enter coefficients a and b (ax + b = 0): ");
  if (scanf("%lf%lf", &a, &b) != 2) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  if (a == 0) {
    if (b == 0) {
      printf("Infinitely many solutions\n");
    } else {
      printf("No solutions\n");
    }
  } else {
    x = -b / a;
    printf("Solution: x = %.2f\n", x);
  }

  return 0;
}
