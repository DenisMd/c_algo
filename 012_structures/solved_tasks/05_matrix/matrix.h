#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stddef.h>

struct matrix {
  size_t rows;
  size_t cols;
  double* data;  // по строкам: элемент (i, j) лежит в data[i * cols + j]
};

// пустая матрица {0, 0, NULL} означает «результата нет»;
// непустой результат освобождает вызывающий через matrix_free
struct matrix matrix_create(size_t rows, size_t cols);
void matrix_free(struct matrix* m);
bool matrix_is_empty(const struct matrix* m);

struct matrix matrix_add(const struct matrix* a, const struct matrix* b);
struct matrix matrix_mul(const struct matrix* a, const struct matrix* b);
struct matrix matrix_transpose(const struct matrix* m);

#endif
