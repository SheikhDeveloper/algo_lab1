#include "merge_sort.h"
#include <stdio.h>
#include <stdlib.h>

int *merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        arr = merge_sort(arr, left, middle);
        arr = merge_sort(arr, middle + 1, right);

        arr = merge(arr, left, middle, right);
    }

    return arr;
}

int *merge(int *arr, int left, int middle, int right) {
    int left_index, right_index, index;
    int left_len = middle - left + 1;
    int right_len = right - middle;

    int right_arr[right_len], left_arr[left_len];
    for (left_index = 0; left_index < left_len; left_index++) {
        *(left_arr + left_index) = *(arr + left + left_index);
    }
    for (right_index = 0; right_index < right_len; right_index++) {
        *(right_arr + right_index) = *(arr + middle + 1 + right_index);
    }

    left_index = 0;
    right_index = 0;
    index = left;
    while (left_index < left_len && right_index < right_len) {
        if (*(left_arr + left_index) <= *(right_arr + right_index)) {
            *(arr + index) = *(left_arr + left_index);
            left_index += 1;
        }
        else {
            *(arr + index) = *(right_arr + right_index);
            right_index += 1;
        }
        index += 1;
    }

    while (left_index < left_len) {
        *(arr + index) = *(left_arr + left_index);
        left_index += 1;
        index += 1;
    }

    while (right_index < right_len) {
        *(arr + index) = *(right_arr + right_index);
        right_index += 1;
        index += 1;
    }
    return arr;
}
