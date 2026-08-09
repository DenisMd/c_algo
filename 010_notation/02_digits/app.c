#include <stdio.h>

int main()
{
  int n = 12345;

  printf("n = %d\n", n);

  while (n > 0) {
    int digit = n % 10;
    n = n / 10;
    printf("%d.", digit);
  }
  printf("\n");

  return 0;
}
