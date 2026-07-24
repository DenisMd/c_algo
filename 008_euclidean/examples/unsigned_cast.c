#include <stdio.h>
#include <limits.h>
#include <assert.h>

void cast_negative_int_to_unsigned(int n)
{
  assert(n < 0);
  printf("n = %.10d\n", n);
  unsigned int positive = (unsigned)n; // -5 mod 2^32
  unsigned int positive_2 = -(unsigned)n; // 2^32 - (-5 mod 2^32)
  printf("%.10u %.10u\n\n", positive, positive_2);
  return;
}

int main()
{
  cast_negative_int_to_unsigned(INT_MIN);
  cast_negative_int_to_unsigned(-1);
  cast_negative_int_to_unsigned(-5);
  return 0;
}