#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    size_t len;
    int *arr;
} Line;

typedef struct Matrix {
    size_t len;
    Line *lines;
} Matrix;

void print_matrix(Matrix m);
void print_line(Line l);
Line *get_line(size_t len);
Matrix *get_matrix(size_t m_len);
int get_size(size_t *len);
int get_int(int *num);
void free_matrix(Matrix *m);
void free_line(Line l);


#endif
