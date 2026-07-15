#include <stdio.h>

int sum_digits(long long a)
{
  if (a < 10) {
    return a;
  }
  return a%10 + sum_digits(a/10);
}

int main()
{
  printf("%d\n", sum_digits(123450));
  return 0;
}