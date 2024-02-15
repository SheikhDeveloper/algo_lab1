#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include "input_tools.h"

Line *get_line(size_t len) {
    printf("Input the line: ");
    Line *l = (Line *)malloc(sizeof(Line));
    l->len = len;
    l->arr = NULL;
    void *tmp;
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

void print_line(const Line line) {
    for (size_t i = 0; i < line.len; i++) {
        printf("%d ", *(line.arr + i));
    }
}

void free_line(Line l) {
    free(l.arr);
}

int sum(Line l) {
    int result = 0;
    for (size_t i = 0; i < l.len; i++) {
        result += *(l.arr + i); 
    }
    return result;
}
