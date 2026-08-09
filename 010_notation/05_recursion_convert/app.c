#include <stdio.h>

void print_forward(int n, int radix)
{
  if (n == 0) return;
  printf("%d ", n % radix);
  print_forward(n / radix, radix);
}

void print_reverse(int n, int radix)
{
  if (n == 0) return;
  print_reverse(n / radix, radix);
  printf("%d ", n % radix);
}

int main()
{
  int n = 13;
  int radix = 2;

  print_forward(n, radix);
  printf("\n");

  print_reverse(n, radix);
  printf("\n");

  return 0;
}
