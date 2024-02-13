#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "states.h"

Matrix *find_max_line_and_sort(Matrix *m);
int sum(Line l);
void merge_sort(Line *l, int left, int right);
void merge(Line *l, int left, int middle, int right);

int main() {
    size_t m_len;
    printf("Input the number of lines in the matrix: ");
    int scanned;
    scanned = get_size(&m_len);
    if (scanned == EOF) {
        printf("\nEOF-ed before any input.\nExiting the programm...\n");
        return 0;
    }
    printf("Input the matrix:\n");
    Matrix *m = get_matrix(m_len);
    if (m == NULL) {
        fprintf(stderr, "%s", states[1]);
        return 1;
    }
    if (m->lines == NULL) {
        free(m);
        return 0;
    }
    printf("Initial matrix:\n");
    print_matrix(*m);
    Matrix *result = find_max_line_and_sort(m);
    printf("Resulting vector:\n");
    print_matrix(*result);
    free_matrix(m);
    if (result->len != 0) {
        free(result->lines);
    }
    free(result);
    printf("%s", states[0]);
    return 0;
}

Matrix *find_max_line_and_sort(Matrix *m) {
    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    result->len = 0;
    if (m->len == 0) {
        return result;
    }
    Line maxima = *(m->lines);
    int max_sum = sum(*(m->lines));
    int cur_sum;
    for (size_t i = 0; i < m->len; i++) {
        cur_sum = sum(*(m->lines + i));
        if (max_sum < cur_sum) {
            maxima = *(m->lines + i);
            max_sum = cur_sum;
        }
    }
    merge_sort(&maxima, 0, maxima.len - 1);
    result->len = 1;
    result->lines = (Line *)malloc(sizeof(Line));
    *(result->lines) = maxima;
    return result;
}

int sum(Line l) {
    int result = 0;
    for (size_t i = 0; i < l.len; i++) {
        result += *(l.arr + i); 
    }
    return result;
}

void merge_sort(Line *l, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(l, left, middle);
        merge_sort(l, middle + 1, right);

        merge(l, left, middle, right);
    }
}

void merge(Line *l, int left, int middle, int right) {
    int i,j,k;
    int left_len = middle - left + 1;
    int right_len = right - middle;

    int right_arr[right_len], left_arr[left_len];
    for (i = 0; i < left_len; i++) {
        *(left_arr + i) = *(l->arr + left + i);
    }
    for (j = 0; j < right_len; j++) {
        *(right_arr + j) = *(l->arr + middle + 1 + j);
    }

    i = 0;
    j = 0;
    k = left;
    while (i < left_len && j < right_len) {
        if (*(left_arr + i) <= *(right_arr + j)) {
            *(l->arr + k) = *(left_arr + j);
            i += 1;
        }
        else {
            *(l->arr + k) = *(right_arr + j);
            j += 1;
        }
        k += 1;
    }

    while (i < left_len) {
        *(l->arr + k) = *(left_arr + i);
        i += 1;
        k += 1;
    }

    while (j < right_len) {
        *(l->arr + k) = *(right_arr + j);
        j += 1;
        k += 1;
    }
}
