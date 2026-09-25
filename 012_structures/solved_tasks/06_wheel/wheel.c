#include "wheel.h"

#include <stdlib.h>

static const struct wheel EMPTY = {0, 0, NULL};

static size_t number_of(size_t index)
{
  return index % 2 == 0 ? 3 * index + 1 : 3 * index + 2;
}

struct wheel wheel_create(size_t limit)
{
  if (limit < 2) {
    return EMPTY;
  }

  size_t size = limit / 3 + 1;
  struct wheel w = {limit, size, calloc(size, 1)};  // нули, то есть IS_PRIME

  if (w.mark == NULL) {
    return EMPTY;
  }

  w.mark[0] = IS_COMPOSITE;  // ячейка числа 1

  if (number_of(size - 1) > limit) {
    w.mark[size - 1] = IS_COMPOSITE;  // последняя ячейка бывает за границей
  }

  for (size_t i = 1; i < size; i++) {
    size_t p = number_of(i);

    if (p > limit / p) {  // то же, что p * p > limit, но без переполнения
      break;
    }

    if (w.mark[i] == IS_COMPOSITE) {
      continue;
    }

    // кратные p, которые сами кандидаты, - это p * (кандидат),
    // а расстояния между кандидатами чередуются 2 и 4
    size_t step = p % 6 == 1 ? 4 * p : 2 * p;
    size_t other = 6 * p - step;

    for (size_t m = p * p; m <= limit;) {
      w.mark[m / 3] = IS_COMPOSITE;
      m += step;

      if (m > limit) {
        break;
      }

      w.mark[m / 3] = IS_COMPOSITE;
      m += other;
    }
  }

  return w;
}

void wheel_free(struct wheel* w)
{
  if (w == NULL) {
    return;
  }

  free(w->mark);
  *w = EMPTY;
}

bool wheel_is_empty(const struct wheel* w)
{
  return w == NULL || w->mark == NULL;
}

bool wheel_is_prime(const struct wheel* w, size_t x)
{
  if (wheel_is_empty(w) || x < 2 || x > w->limit) {
    return false;
  }

  if (x == 2 || x == 3) {
    return true;
  }

  if (x % 6 != 1 && x % 6 != 5) {
    return false;
  }

  return w->mark[x / 3] == IS_PRIME;
}

size_t wheel_count(const struct wheel* w)
{
  if (wheel_is_empty(w)) {
    return 0;
  }

  size_t count = 0;

  if (w->limit >= 2) {
    count++;
  }

  if (w->limit >= 3) {
    count++;
  }

  for (size_t i = 1; i < w->size; i++) {
    if (w->mark[i] == IS_PRIME) {
      count++;
    }
  }

  return count;
}

size_t wheel_largest(const struct wheel* w)
{
  if (wheel_is_empty(w)) {
    return 0;
  }

  for (size_t i = w->size; i-- > 1;) {
    if (w->mark[i] == IS_PRIME) {
      return number_of(i);
    }
  }

  if (w->limit >= 3) {
    return 3;
  }

  return 2;
}

size_t wheel_bytes(const struct wheel* w)
{
  if (wheel_is_empty(w)) {
    return 0;
  }

  return w->size;
}
