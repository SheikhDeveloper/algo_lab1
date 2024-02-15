#include <stdlib.h>
#include <stdio.h>
#include "lib/matrix.h"
#include "states.h"
#include "lib/input_tools.h"

Matrix *find_max_line_and_sort(const Matrix *m);
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

Matrix *find_max_line_and_sort(const Matrix *m) {
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
    int left_index, right_index, index;
    int left_len = middle - left + 1;
    int right_len = right - middle;

    int right_arr[right_len], left_arr[left_len];
    for (left_index = 0; left_index < left_len; left_index++) {
        *(left_arr + left_index) = *(l->arr + left + left_index);
    }
    for (right_index = 0; right_index < right_len; right_index++) {
        *(right_arr + right_index) = *(l->arr + middle + 1 + right_index);
    }

    left_index = 0;
    right_index = 0;
    index = left;
    while (left_index < left_len && right_index < right_len) {
        if (*(left_arr + left_index) <= *(right_arr + right_index)) {
            *(l->arr + index) = *(left_arr + left_index);
            left_index += 1;
        }
        else {
            *(l->arr + index) = *(right_arr + right_index);
            right_index += 1;
        }
        index += 1;
    }

    while (left_index < left_len) {
        *(l->arr + index) = *(left_arr + left_index);
        left_index += 1;
        index += 1;
    }

    while (right_index < right_len) {
        *(l->arr + index) = *(right_arr + right_index);
        right_index += 1;
        index += 1;
    }
}
