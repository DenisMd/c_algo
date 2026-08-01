#include <stdio.h>
#include <assert.h>

#define MAXN 94 // fib(93) — последнее, что влезает в unsigned long long

unsigned long long memo[MAXN]; // глобальный -> .bss -> нули на старте
long long calls;               // тоже глобальный: считаем вызовы fib()

unsigned long long fib(int n) {
  assert(n <= MAXN-1);
  calls++;
  if(n < 2) {
    return (unsigned long long)n; // база: fib(0)=0, fib(1)=1
  }
  if(memo[n]) {
    return memo[n]; // уже считали раньше — берём готовое из кэша
  }
  return memo[n] = fib(n - 1) + fib(n - 2); // посчитали и запомнили
}

int main()
{
  for(int n=0; n <= 15; n++) {
    printf("fib(%2d) = %llu\n", n, fib(n));
  }

  printf("...\n");
  printf("fib(93) = %llu\n", fib(93));

  printf("всего вызовов fib(): %lld\n", calls);

  return 0;
}
