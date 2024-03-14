#include "item.h"

#define N_MAX 15

int itemarr_read(FILE *f, itm *pitems, int n_max, int *n);
void itemarr_print(FILE *f, const itm *pitems, int n);
void sort(itm *items, int n);
