#include <stdio.h>

int main()
{
  int n, sum = 0;

  printf("Enter integer N: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  if (n < 0) {
    fprintf(stderr, "Must be positive!\n");
    return 1;
  }

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  };

  printf("%d\n", sum);

  return 0;
}
