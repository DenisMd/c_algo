#include <stdio.h>

#ifndef VERBOSE
#define VERBOSE 0
#endif


/*
long long res = 1;
for(int i=1; i<=n; i++) {
  res *= i;
}
*/
long long factorial(int n)
{
  static int counter = 0;
  counter++;
  if (VERBOSE) {
    printf("factorial(%d), counter=%d\n", n, counter);
  }
  if (n == 0) {
    return 1;
  }
  return n * factorial(n-1); // int -> long long
}


int main()
{
  int n;
  if (scanf("%d",&n) != 1) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  printf("factorial(%d) = %lld\n", n, factorial(n));

  return 0;
}