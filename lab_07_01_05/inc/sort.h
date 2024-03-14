#include <stdio.h>
#include <string.h>
#include "err.h"

#define EPS 10e-5

int comp_int(const void *first, const void *second);
int comp_double(const void *first, const void *second);
int comp_string(const void *first, const void *second);
void swap(char *l, char *r, size_t elem_size);
void mysort(void *beg, int number, size_t size, int (*compare)(const void *, const void *));
