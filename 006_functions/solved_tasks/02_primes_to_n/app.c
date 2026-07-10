#include <stdio.h>
#include <stdlib.h>

void read_input(int *n)
{
  printf("Enter integer N: ");
  if (scanf("%d", n) != 1) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int is_prime(int n)
{
  if (n <= 1) {
    return 0;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

void print_prime_numbers_to_n(int n)
{
  for (int i = 2; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d\n", i);
    }
  }
}

int main()
{
  int n;
  read_input(&n);

  print_prime_numbers_to_n(n);

  return 0;
}
