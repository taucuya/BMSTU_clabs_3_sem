#include <stdio.h>
#include "error.h"

#define NAME_LEN 25
#define EPS 10e-5

typedef struct item 
{
    char name[NAME_LEN + 1];
    double weight;
    double volume;
} itm;

int item_read(FILE *f, itm *pitem);
void item_print(FILE *f, const itm *pitem);