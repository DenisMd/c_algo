#include "matrix.h"

#include <stdint.h>
#include <stdlib.h>

static const struct matrix EMPTY = {0, 0, NULL};

struct matrix matrix_create(size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0 || rows > SIZE_MAX / cols / sizeof(double)) {
    return EMPTY;
  }

  struct matrix m = {rows, cols, calloc(rows * cols, sizeof(double))};

  if (m.data == NULL) {
    return EMPTY;
  }

  return m;
}

void matrix_free(struct matrix* m)
{
  if (m == NULL) {
    return;
  }

  free(m->data);
  *m = EMPTY;
}

bool matrix_is_empty(const struct matrix* m)
{
  return m == NULL || m->data == NULL;
}

struct matrix matrix_add(const struct matrix* a, const struct matrix* b)
{
  if (matrix_is_empty(a) || matrix_is_empty(b) || a->rows != b->rows ||
      a->cols != b->cols) {
    return EMPTY;
  }

  struct matrix sum = matrix_create(a->rows, a->cols);

  if (matrix_is_empty(&sum)) {
    return EMPTY;
  }

  for (size_t k = 0; k < a->rows * a->cols; k++) {
    sum.data[k] = a->data[k] + b->data[k];  // раскладка одинаковая
  }

  return sum;
}

struct matrix matrix_mul(const struct matrix* a, const struct matrix* b)
{
  if (matrix_is_empty(a) || matrix_is_empty(b) || a->cols != b->rows) {
    return EMPTY;
  }

  struct matrix product = matrix_create(a->rows, b->cols);

  if (matrix_is_empty(&product)) {
    return EMPTY;
  }

  for (size_t i = 0; i < a->rows; i++) {
    for (size_t j = 0; j < b->cols; j++) {
      double s = 0.0;

      for (size_t k = 0; k < a->cols; k++) {
        s += a->data[i * a->cols + k] * b->data[k * b->cols + j];
      }

      product.data[i * product.cols + j] = s;
    }
  }

  return product;
}

struct matrix matrix_transpose(const struct matrix* m)
{
  if (matrix_is_empty(m)) {
    return EMPTY;
  }

  struct matrix t = matrix_create(m->cols, m->rows);

  if (matrix_is_empty(&t)) {
    return EMPTY;
  }

  for (size_t i = 0; i < m->rows; i++) {
    for (size_t j = 0; j < m->cols; j++) {
      t.data[j * t.cols + i] = m->data[i * m->cols + j];
    }
  }

  return t;
}
