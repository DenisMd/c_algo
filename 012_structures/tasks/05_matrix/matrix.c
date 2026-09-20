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
    // TODO: пустые или разные размеры -> EMPTY;
    //       результат через matrix_create, сложить поэлементно
    return EMPTY;
}

struct matrix matrix_mul(const struct matrix* a, const struct matrix* b)
{
    // TODO: a->cols != b->rows -> EMPTY; результат a->rows x b->cols;
    //       элемент (i, j) - сумма a(i, k) * b(k, j) по k
    return EMPTY;
}

struct matrix matrix_transpose(const struct matrix* m)
{
    // TODO: результат m->cols x m->rows, элемент (i, j) переезжает в (j, i)
    return EMPTY;
}
