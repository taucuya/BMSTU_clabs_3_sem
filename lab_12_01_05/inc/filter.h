#ifndef _FILTER_H_
#define _FILTER_H_

#include <stdio.h>
#include "err.h"
#include <stdlib.h>

#define MAX_SIZE 100

int key(const int *mas, const int *end, int **new_beg, int **new_end);

#endif