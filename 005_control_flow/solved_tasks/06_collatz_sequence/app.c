#include <stdio.h>

int main()
{
  int n, steps = 0;

  printf("Enter integer N: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    return 1;
  }

  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
    steps++;
  }

  printf("%d\n", steps);

  return 0;
}
