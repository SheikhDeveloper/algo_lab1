#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    size_t len;
    int *arr;
} Line;

typedef struct LineMonad {
    Line line;
    char *error;
} EitherLine;

typedef struct Matrix {
    size_t len;
    Line *lines;
} Matrix;

typedef struct MatrixMonad {
    Matrix matrix;
    char *error;
} EitherMatr;

EitherMatr return_matrix(Matrix m);
EitherMatr return_matrix_error(char *e);
EitherLine return_line(Line l);
EitherLine return_line_error(char *e);
EitherMatr bind_matrix(EitherMatr (*func)(Matrix), EitherMatr m);
void print_matrix(EitherMatr m);
void print_line(EitherLine l);
EitherLine get_line(size_t len);
EitherMatr get_matrix(size_t m_len);
size_t get_size();
int get_int();
void free_matrix(Matrix m);
void free_line(Line l);


#endif
