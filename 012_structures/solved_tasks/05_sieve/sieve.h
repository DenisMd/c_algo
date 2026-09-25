#ifndef SIEVE_H
#define SIEVE_H

#include <stdbool.h>
#include <stddef.h>

#define IS_PRIME 0
#define IS_COMPOSITE 1

// решето на все числа от 0 до limit: байт на число
struct sieve {
  size_t limit;
  unsigned char* mark;  // IS_PRIME или IS_COMPOSITE
};

struct sieve sieve_create(size_t limit);  // пустое, если памяти не хватило
void sieve_free(struct sieve* s);
bool sieve_is_empty(const struct sieve* s);

bool sieve_is_prime(const struct sieve* s, size_t x);
size_t sieve_count(const struct sieve* s);
size_t sieve_largest(const struct sieve* s);
size_t sieve_bytes(const struct sieve* s);

#endif
