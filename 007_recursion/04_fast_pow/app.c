#include <stdio.h>


#ifndef VERBOSE
#define VERBOSE 0
#endif

long long counter = 1;

// base ^ exponent
long long fast_pow(int base, int exponent) {
  counter++;
  if (exponent == 0) {
    return 1; // base^0 == 1
  }
  if (exponent % 2 == 0) {
    long long half = fast_pow(base, exponent/2);
    return half*half;
  }
  return base * fast_pow(base, exponent-1); // a^5 = a * a^4
}

int main()
{
  int base, exponent;
  if (scanf("%d%d", &base, &exponent) != 2) {
    fprintf(stderr, "invalid input!\n");
    return 1;
  }  

  printf("%d^%d = %lld\n", base, exponent, fast_pow(base, exponent));
  if (VERBOSE) {
    printf("number of calls = %lld\n", counter);
  }

  return 0;
}