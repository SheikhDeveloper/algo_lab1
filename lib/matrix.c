#include "matrix.h"
#include "input_tools.c"
#include <stdio.h>
#include <stdlib.h>

void print_matrix(const Matrix matr) {
    Line l;
    for (size_t i = 0; i < matr.len; i++) {
        l = *(matr.lines + i);
        print_line(l);
        printf("\n");
    }
}

Matrix *matrix_init(size_t len) {
    Matrix *matr = (Matrix *)malloc(sizeof(Matrix));
    void *tmp;
    matr->len = len;
    matr->lines = NULL;
    tmp = realloc(matr->lines, matr->len * sizeof(Line));
    if (tmp == NULL) {
        free_matrix(matr);
        return NULL;
    }
    matr->lines = tmp;
    return matr;
}

Matrix *get_matrix(size_t m_len) {
    Matrix *matr = matrix_init(m_len);
    if (matr == NULL) return NULL;
    Line *l;
    size_t line_len;
    int scanned;
    void *tmp;
    for (size_t i = 0; i < matr->len; i++) {
        printf("Input length of the line in the matrix: ");
        scanned = get_size(&line_len);
        if (scanned == EOF) {
            matr->len = i;
            tmp = realloc(matr->lines, matr->len * sizeof(Line));
            if (tmp == NULL && matr->len != 0) {
                free_matrix(matr);
                return NULL;
            }
            matr->lines = tmp;
            printf("\n");
            return matr;
        }
        l = get_line(line_len);
        if (l == NULL) {
            free_matrix(matr); 
            return NULL;
        }
        *(matr->lines + i) = *l;
        free(l);
    }
    return matr;
}

void free_matrix(Matrix *m) {
    if (m == NULL) return;
    for (size_t i = 0; i < m->len; i++) {
        free_line(*(m->lines + i));
    }
    free(m->lines);
    free(m);
}
