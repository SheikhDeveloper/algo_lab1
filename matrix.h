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
    int len;
    EitherLine *lines;
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
EitherMatr print_matrix(EitherMatr m);
EitherLine bind_line(EitherLine (*func)(Line), EitherMatr l);
EitherLine print_line(EitherLine l);
EitherMatr get_matrix();
Line get_line();
void print_matrix(Matrix m);
void print_line(Line l);
