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
    Line *result = NULL;
    if (m->len != 0) {
        result = find_max_line_and_sort(m);
    }
    printf("Resulting vector:\n");
    free_matrix(m);
    if (result != NULL) {
        print_line(*result);
        free_line(*result);
        free(result);
    }
    printf("%s", states[0]);
    return 0;
}

Line *find_max_line_and_sort(const Matrix *m) {
    Line *maxima = find_max_line(m);
    maxima->arr = merge_sort(maxima->arr, 0, maxima->len - 1);
    return maxima;
}
