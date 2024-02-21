#ifndef MATRIX_H
#define MATRIX_H

#include "line.h"

typedef struct Matrix {
    size_t len;
    Line *lines;
} Matrix;

Matrix *matrix_init(size_t len);
void print_matrix(const Matrix m);
Matrix *get_matrix(size_t m_len);
void free_matrix(Matrix *m);
Line *find_max_line(const Matrix *m);

#endif
