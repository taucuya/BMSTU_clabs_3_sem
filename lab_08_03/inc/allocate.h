#ifndef _ALLOCATE_H_
#define _ALLOCATE_H_

#include "gen.h"

int **allocate_matrix(int n, int m);
int **realloc_matrix(int *first, int size, int n);

#endif