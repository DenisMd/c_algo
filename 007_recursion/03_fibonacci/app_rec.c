#include <stdio.h>

#ifndef VERBOSE
#define VERBOSE 0
#endif

long long counter = 1;

long long fib(int n)
{
  counter++;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  return fib(n-1) + fib(n - 2);
}

int main()
{
  int n;
  if (scanf("%d",&n) != 1) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  printf("fib(%d) = %lld\n", n, fib(n));
  if (VERBOSE) {
    printf("number of calls: %lld\n", counter);
  }

  return 0;
}