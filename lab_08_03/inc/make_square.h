#ifndef _MAKE_SQUARE_H_
#define _MAKE_SQUARE_H_ 

#include "gen.h"


void find_max(int *first, int m, int n, int *i, int *j);
void rebuild_to_square(int *first, int *m, int *n);
void delete_row(int *first, int row, int n, int m);
void delete_column(int *first, int column, int n, int m);

#endif 