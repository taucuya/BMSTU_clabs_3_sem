#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "gen.h"
#include "allocate.h"
#include "mult.h"

int make_result(int *first, int *second, int *result, size_t final);
void copy(int *src, int *dst, size_t final);
void make_zeroes(int *res, size_t final);

#endif