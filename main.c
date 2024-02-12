#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

EitherMatr find_max_line(Matrix m);
int sum(Line l);

int main() {
    size_t m_len;
    printf("Input the number of lines in the matrix: ");
    m_len = get_size();
    printf("Input the matrix:\n");
    EitherMatr m = get_matrix(m_len);
    printf("Initial matrix:\n");
    print_matrix(m);
    if (m.error == NULL) {
        EitherMatr result = bind_matrix(find_max_line, m);
        printf("Resulting vector:\n");
        print_matrix(result);
        free_matrix(result.matrix);
        free_matrix(m.matrix);
    }
    return 0;
}

EitherMatr find_max_line(Matrix m) {
    Line maxima = *(m.lines);
    int max_sum = sum(*(m.lines));
    int cur_sum;
    for (size_t i = 0; i < m.len; i++) {
        cur_sum = sum(*(m.lines + i));
        if (max_sum < cur_sum) {
            maxima = *(m.lines + i);
            max_sum = cur_sum;
        }
    }
    EitherMatr result;
    Matrix res;
    res.lines = (Line *)malloc(sizeof(Line));
    *(res.lines) = maxima;
    result = return_matrix(res);
    return result;
}

int sum(Line l) {
    int result = 0;
    for (size_t i = 0; i < l.len; i++) {
        result += *(l.arr + i); 
    }
    return result;
}
