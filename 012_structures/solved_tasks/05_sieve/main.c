#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"

const double MB = 1024.0 * 1024.0;

void read_input(size_t* limit)
{
  printf("Enter limit: ");

  if (scanf("%zu", limit) != 1 || *limit < 2) {
    fprintf(stderr, "Incorrect input!\n");
    exit(1);
  }
}

int main()
{
  size_t limit;

  read_input(&limit);

  printf("limit = %zu, sieve needs %.1f MB (byte per number)\n", limit,
         (limit + 1) / MB);

  struct sieve s = sieve_create(limit);

  if (sieve_is_empty(&s)) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  size_t largest = sieve_largest(&s);

  assert(sieve_is_prime(&s, largest));

  printf("primes = %zu\n", sieve_count(&s));
  printf("largest prime = %zu\n", largest);
  printf("sieve size = %.1f MB\n", sieve_bytes(&s) / MB);

  sieve_free(&s);

  return 0;
}
