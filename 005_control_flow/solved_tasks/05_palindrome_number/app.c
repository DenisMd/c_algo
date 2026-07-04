#include <stdio.h>

int main()
{
  int n, original, reversed = 0;

  printf("Enter integer N: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  original = n;
  if (n < 0) {
    fprintf(stderr, "Must be positive!\n");
    return 1;
  }

  while (n > 0) {
    reversed = reversed * 10 + n % 10;
    printf("reversed %d\n", reversed);
    n /= 10;
  }

  printf("%d\n", original == reversed);

  return 0;
}
