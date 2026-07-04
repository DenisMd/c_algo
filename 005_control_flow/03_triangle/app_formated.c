#include <stdio.h>

int main()
{
  double a, b, c;
  printf("Enter three triangle sides: ");
  if (scanf("%lf%lf%lf", &a, &b, &c) != 3) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  if (a <= 0 || b <= 0 || c <= 0) {
    printf("Side lengths must be positive numbers.\n");
    return 2;
  }

  if (a + b <= c || a + c <= b || b + c <= a) {
    printf("A triangle with these side lengths does not exist.\n");
    return 3;
  }

  printf("The triangle exists.\n");

  if (a == b && b == c) {
    printf("Type: equilateral\n");
  } else if (a == b || a == c || b == c) {
    printf("Type: isosceles\n");
  } else {
    printf("Type: scalene\n");
  }

  return 0;
}