#ifndef LINE_H
#define LINE_H

#include <stdio.h>

typedef struct Line {
    size_t len;
    int *arr;
} Line;

Line *line_init(size_t len);
Line *get_line(size_t len);
void print_line(const Line l);
void free_line(Line l);
int sum(Line l);
Line copy_line(Line l);

#endif
