#include "sieve.h"

#include <stdlib.h>

static const struct sieve EMPTY = {0, NULL};

struct sieve sieve_create(size_t limit)
{
  if (limit < 2) {
    return EMPTY;
  }

  struct sieve s = {limit, calloc(limit + 1, 1)};  // нули, то есть IS_PRIME

  if (s.mark == NULL) {
    return EMPTY;
  }

  s.mark[0] = IS_COMPOSITE;
  s.mark[1] = IS_COMPOSITE;

  for (size_t p = 2; p <= limit / p; p++) {  // то же, что p * p <= limit
    if (s.mark[p] == IS_COMPOSITE) {
      continue;
    }

    for (size_t m = p * p; m <= limit; m += p) {  // до p * p всё уже вычеркнуто
      s.mark[m] = IS_COMPOSITE;
    }
  }

  return s;
}

void sieve_free(struct sieve* s)
{
  if (s == NULL) {
    return;
  }

  free(s->mark);
  *s = EMPTY;
}

bool sieve_is_empty(const struct sieve* s)
{
  return s == NULL || s->mark == NULL;
}

bool sieve_is_prime(const struct sieve* s, size_t x)
{
  if (sieve_is_empty(s) || x > s->limit) {
    return false;
  }

  return s->mark[x] == IS_PRIME;
}

size_t sieve_count(const struct sieve* s)
{
  if (sieve_is_empty(s)) {
    return 0;
  }

  size_t count = 0;

  for (size_t x = 2; x <= s->limit; x++) {
    if (s->mark[x] == IS_PRIME) {
      count++;
    }
  }

  return count;
}

size_t sieve_largest(const struct sieve* s)
{
  if (sieve_is_empty(s)) {
    return 0;
  }

  for (size_t x = s->limit; x >= 2; x--) {
    if (s->mark[x] == IS_PRIME) {
      return x;
    }
  }

  return 0;
}

size_t sieve_bytes(const struct sieve* s)
{
  if (sieve_is_empty(s)) {
    return 0;
  }

  return s->limit + 1;
}
