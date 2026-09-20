#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void read_matrix(struct matrix* m)
{
    size_t rows, cols;

    if (scanf("%zu %zu", &rows, &cols) != 2 || rows == 0 || cols == 0) {
        fprintf(stderr, "Incorrect input!\n");
        exit(1);
    }

    *m = matrix_create(rows, cols);

    if (matrix_is_empty(m)) {
        fprintf(stderr, "Allocation failed!\n");
        exit(1);
    }

    for (size_t k = 0; k < rows * cols; k++) {  // во вводе числа идут по строкам
        if (scanf("%lf", &m->data[k]) != 1) {
            fprintf(stderr, "Incorrect input!\n");
            matrix_free(m);
            exit(1);
        }
    }
}

void read_input(struct matrix* a, struct matrix* b)
{
    printf("Enter two matrices (rows cols, then numbers by rows): ");
    read_matrix(a);
    read_matrix(b);
    printf("\n");
}

void print_matrix(const struct matrix* m)
{
    if (matrix_is_empty(m)) {
        printf("undefined\n");
        return;
    }

    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            printf("%8.2f", m->data[i * m->cols + j]);
        }

        printf("\n");
    }
}

int main()
{
    struct matrix a, b;

    read_input(&a, &b);

    struct matrix sum = matrix_add(&a, &b);
    struct matrix ab = matrix_mul(&a, &b);
    struct matrix ba = matrix_mul(&b, &a);
    struct matrix at = matrix_transpose(&a);

    assert(matrix_is_empty(&ab) || (ab.rows == a.rows && ab.cols == b.cols));
    assert(matrix_is_empty(&at) || (at.rows == a.cols && at.cols == a.rows));

    printf("A + B:\n");
    print_matrix(&sum);
    printf("A * B:\n");
    print_matrix(&ab);
    printf("B * A:\n");
    print_matrix(&ba);
    printf("A^T:\n");
    print_matrix(&at);

    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&sum);
    matrix_free(&ab);
    matrix_free(&ba);
    matrix_free(&at);

    return 0;
}
