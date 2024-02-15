#ifndef MATRIX_H
#define MATRIX_H

#include "line.h"

typedef struct Matrix {
    size_t len;
    Line *lines;
} Matrix;

void print_matrix(Matrix m);
Matrix *get_matrix(size_t m_len);
void free_matrix(Matrix *m);

#endif
