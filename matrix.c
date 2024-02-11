#include "matrix.h"

EitherMatr return_matrix(Matrix m) {return (EitherMatr) { .matrix = m, .error = NULL }; }
EitherMatr return_matrix_error(char *e) {return (EitherMatr) { .matrix = (Matrix) { .len = 0, .lines = NULL},  .error = e }; }
EitherLine return_line(Line l) {return (EitherLine) { .line = l, .error = NULL}; }
EitherLine return_line_error(char *e) {return (EitherLine) { .line = (Line) { .len = 0, .line = NULL}, .error = e }; }
EitherMatr bind_matrix(EitherMatr (*func)(Matrix), EitherMatr m) {
    return (m.error != NULL) ? m : func(m.matrix); 
}
void print_matrix(EitherMatr m) {
    if (m.error != NULL) fprintf(stderr, "%s", m.error);
    else {
        Matrix matr = m.matrix;
        EitherLine l;
        for (size_t i = 0; i < matr.len; i++) {
            l = *(matr.lines + i);
            print_line(l);
            printf("\n");
        }
    }
}
EitherLine bind_line(EitherLine (*func)(Line), EitherLine l) {
    return (l.error != NULL) ? l : func(l.line);
}

void print_line(EitherLine l) {
    if (l.error != NULL) printf("%s", l.error);
    else  {
        Line line = l.line;
        for (size_t i = 0; i < line.len; i++) {
            printf("%d ", *(line.arr + i));
        }
    }
}

EitherMatr *get_matrix(size_t m_len) {
    EitherMatr m;
    Matrix matr;
    Line *tmp;
    matr.len = m_len;
    matr.lines = NULL;
    int scanned = 0;
    Line l;
    size_t line_len;
    for (size_t i = 0; i < m; i++) {
        printf("Input length of the line in the matrix: ");
        line_len = get_size()
        l = get_line();
        tmp = realloc(matr.lines, matr.len * sizeof(EitherLine));
        if (tmp == NULL) { 
            m = return_matrix_error(errors[0]);
            return m;
         }
        *(matr.lines + i) = l;
    }
    m = return_matrix(matr); 
    return m;
}

EitherLine get_line(size_t len) {
    EitherLine line;
    Line l; 
    int *tmp;
    int num;
    for (size_t i = 0; i < len; i++) {
        num = get_int();
        l.len += 1;
        tmp = realloc(l.arr, l.len * sizeof(int));
        if (tmp == NULL) {
            line = return_line_error(errors[0]);
        }
}

int get_int() {
    int num;
    int scanned = scanf("%d", &num);
    while (scanned != 1) {
        if (scanned == EOF) return EOF;
        fprintf(stderr, "%s", errors[1]);
        scanf("%*[^\n]");
        scanned = scanf("%d", &num);
    }
    return num;
}

size_t get_size() {
    int len = get_int();
    while (len < 0) {
        fprintf(stderr, "%s", errors[2]);
        len = get_int();
    }
    size_t result = (size_t) len;
    return result;
}
