#include <stdio.h>


long long fib(int n)
{
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  long long fib_prev_prev = 0;
  long long fib_prev = 1;
  long long fib_n;
  for (int i = 2; i <= n; i++) {
    fib_n = fib_prev_prev + fib_prev;
    fib_prev_prev = fib_prev;
    fib_prev = fib_n;
  }
  return fib_n;
}

int main()
{
  int n;
  if (scanf("%d",&n) != 1) {
    fprintf(stderr, "invalid input\n");
    return 1;
  }

  printf("fib(%d) = %lld\n", n, fib(n));

  return 0;
}