#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#define NAME_LEN 25
#define EPS 10e-5

typedef struct item 
{
    char *name;
    double weight;
    double volume;
} itm;

int item_read(FILE *f, itm *pitem);
void item_print(FILE *f, itm *pitem);

#endif