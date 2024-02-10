#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    size_t len;
    int *arr;
} Line;

typedef struct Matrix {
    int len;
    Line *lines;
} Matrix;

Matrix make_matrix(int m);
Line input_line(size_t len);
void print_matrix(Matrix m);
void print_line(Line l);
