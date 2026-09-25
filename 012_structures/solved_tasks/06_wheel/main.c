#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "wheel.h"

const double MB = 1024.0 * 1024.0;
const size_t CHECK_LIMIT = 1000;  // до этого сверяемся с проверкой делением

bool is_prime_slow(size_t x)
{
  if (x < 2) {
    return false;
  }

  for (size_t d = 2; d <= x / d; d++) {
    if (x % d == 0) {
      return false;
    }
  }

  return true;
}

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

  struct wheel w = wheel_create(limit);

  if (wheel_is_empty(&w)) {
    fprintf(stderr, "Allocation failed!\n");
    return 1;
  }

  size_t check = limit < CHECK_LIMIT ? limit : CHECK_LIMIT;

  for (size_t x = 0; x <= check; x++) {
    assert(wheel_is_prime(&w, x) == is_prime_slow(x));
  }

  printf("limit = %zu\n", limit);
  printf("all numbers: %.1f MB, candidates 6k+-1: %.1f MB\n", (limit + 1) / MB,
         wheel_bytes(&w) / MB);
  printf("primes = %zu, largest = %zu\n", wheel_count(&w), wheel_largest(&w));

  wheel_free(&w);

  return 0;
}
