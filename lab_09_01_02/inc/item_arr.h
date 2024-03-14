#ifndef _ITEM_ARR_H_
#define _ITEM_ARR_H_

#include "item.h"
#include <string.h>

#define N_MAX 20
#define ITEM_SIZE 41

int itemarr_read(FILE *f, itm **pitems, int n_max);
void itemarr_print(FILE *f, itm **pitems, int n);
int count(FILE *f, int n_max, int *n);

#endif