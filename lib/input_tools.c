#include <stdio.h>
#include "input_tools.h"

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
