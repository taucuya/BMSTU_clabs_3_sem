#ifndef _INPUT_H_
#define _INPUT_H_

#include "gen.h"

int read_from_file(char *filename, vec *products, char **uniq, int *uniq_num);
int count_structs(char *filename, int *num);

#endif