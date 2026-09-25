#ifndef WHEEL_H
#define WHEEL_H

#include <stdbool.h>
#include <stddef.h>

#define IS_PRIME 0
#define IS_COMPOSITE 1

// хранятся только кандидаты 6k-1 и 6k+1: 1, 5, 7, 11, 13, 17, ...
// ячейка i отвечает числу 3*i + 1 при чётном i и 3*i + 2 при нечётном,
// обратно: i = x / 3. Числа 2 и 3 в шаблон не попадают, они особые
struct wheel {
  size_t limit;
  size_t size;          // ячеек: limit / 3 + 1
  unsigned char* mark;  // IS_PRIME или IS_COMPOSITE
};

struct wheel wheel_create(size_t limit);  // пустое, если памяти не хватило
void wheel_free(struct wheel* w);
bool wheel_is_empty(const struct wheel* w);

bool wheel_is_prime(const struct wheel* w, size_t x);
size_t wheel_count(const struct wheel* w);
size_t wheel_largest(const struct wheel* w);
size_t wheel_bytes(const struct wheel* w);

#endif
