#include "matrix.h"

void print_matrix(Matrix matr) {
    Line l;
    for (size_t i = 0; i < matr.len; i++) {
        l = *(matr.lines + i);
        print_line(l);
        printf("\n");
    }
}

void print_line(Line line) {
    for (size_t i = 0; i < line.len; i++) {
        printf("%d ", *(line.arr + i));
    }
}

Matrix *get_matrix(size_t m_len) {
    Matrix *matr = (Matrix *)malloc(sizeof(Matrix));
    Line *tmp;
    matr->len = m_len;
    matr->lines = NULL;
    tmp = realloc(matr->lines, matr->len * sizeof(Line));
    if (tmp == NULL) {
        free_matrix(matr);
        return NULL;
    }
    matr->lines = tmp;
    Line *l;
    size_t line_len;
    int scanned;
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

Line *get_line(size_t len) {
    Line *l = (Line *)malloc(sizeof(Line));
    l->len = len;
    l->arr = NULL;
    int *tmp;
    tmp = realloc(l->arr, l->len * sizeof(int));
    if (tmp == NULL && l->len != 0) {
        free(l);
        return NULL;
    }
    l->arr = tmp;
    int num;
    int scanned;
    for (size_t i = 0; i < len; i++) {
        scanned = get_int(&num);
        if (scanned == EOF) {
            l->len = i;
            tmp = realloc(l->arr, l->len * sizeof(int));
            if (tmp == NULL && l->len != 0) {
                free(l);
                return l;
            }
            l->arr = tmp;
            break;
            }
        *(l->arr + i) = num;
    }
    return l;
}

int get_int(int *num) {
    int scanned = scanf("%d", num);
    if (scanned == EOF) return EOF;
    while (scanned != 1) {
        if (scanned == EOF) return EOF;
        scanf("%*[^\n]");
        fprintf(stderr, "Incorrect input format.\nTry again: ");
        scanned = scanf("%d", num);
    }
    return scanned;
}

int get_size(size_t *len) {
    int *value = (int *)len;
    int scanned = get_int(value);
    if (scanned == EOF) return EOF;
    while (*value < 0) {
        fprintf(stderr, "%s", "Size cannot be negative.\nTry again: ");
        scanned = get_int(value);
        if (scanned == EOF) return EOF;
    }
    *len = (size_t) *value;
    return scanned;
}

void free_matrix(Matrix *m) {
    for (size_t i = 0; i < m->len; i++) {
        free_line(*(m->lines + i));
    }
    free(m->lines);
    free(m);
}

void free_line(Line l) {
    free(l.arr);
}
