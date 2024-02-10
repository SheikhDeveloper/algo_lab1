#include "matrix.h"

EitherMatr *get_matrix() {
    EitherMatr m;
    Matrix matr;
    Line *tmp;
    matr->len = 0;
    matr->lines = NULL;
    int scanned = 0;
    Line l;
    while (scanned != EOF) {
        l = get_line();
        matr.len += 1;
        tmp = realloc(m.lines, m.len * sizeof(Line));
        if (tmp == NULL) return_matrix_error("Memory allocation failed\n");
        *(m.lines + m.len) = l;
    }
}

Line get_line() {
    Line l;
    int num;
    int scanned = get_int(&n);
    while (scanned != 
}

get_int(int *num) {
    int scanned = scanf("%d", num);
    while (scanned != 1) {
        if (scanned == EOF) return EOF;
        scanf("%*[^\n]");
        scanned = scanf("%d", num);
    }
}
