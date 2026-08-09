#include <stdio.h>

long long fast_pow(long long base, int exp)
{
  long long result = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result *= base;
    }
    base *= base;
    exp /= 2;
  }

  return result;
}

int main()
{
  printf("2^10 = %lld\n", fast_pow(2, 10));
  printf("3^5  = %lld\n", fast_pow(3, 5));
  printf("5^0  = %lld\n", fast_pow(5, 0));
  printf("7^11 = %lld\n", fast_pow(7, 11));

  return 0;
}
