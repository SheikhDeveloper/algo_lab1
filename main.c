#include <stdlib.h>
#include <stdio.h>
#include "lib/matrix.h"
#include "states.h"
#include "lib/input_tools.h"
#include "lib/merge_sort.h"

Line *find_max_line_and_sort(const Matrix *m);

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
    Line *result = find_max_line_and_sort(m);
    printf("Resulting vector:\n");
    print_line(*result);
    free_matrix(m);
    free_line(*result);
    free(result);
    printf("%s", states[0]);
    return 0;
}

Line *find_max_line_and_sort(const Matrix *m) {
    Line *result = (Line *)malloc(sizeof(Line)); 
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
    maxima.arr = merge_sort(maxima.arr, 0, maxima.len - 1);
    *result = copy_line(maxima);
    return result;
}
