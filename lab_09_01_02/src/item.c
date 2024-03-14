#define  _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int item_read(FILE *f, itm *pitem) 
{
    char *buf = NULL;
    size_t len = 0;
    double weight;
    double volume;
    size_t length;

    length = getline(&buf, &len, f);
    if ((int) length == -1 || length == 1)
    {
        free(buf);
        return ERR_IO;
    }
    buf[length - 1] = '\0';
    char sign;
    int check1 = fscanf(f, "%lf%c", &weight, &sign);
    if (check1 == 0 || check1 == -1 || (check1 == 2 && sign != '\n') || weight <= 0)
    {
        free(buf);
        return ERR_DATA;
    }

    int check2 = fscanf(f, "%lf%c", &volume, &sign);
    if (check2 == 0 || check2 == -1 || (check2 == 2 && sign != '\n') || volume <= 0)
    {
        free(buf);
        return ERR_DATA;
    }

    pitem->name = malloc(length);
    if (!pitem->name)
    {
        free(buf);
        return ERR_ALLOC;
    }

    strcpy(pitem->name, buf);
    pitem->weight = weight;
    pitem->volume = volume;
    free(buf);
    return ERR_OK;    
}

void item_print(FILE *f, itm *pitem) 
{
    fprintf(f, "%s\n", pitem->name);
    fprintf(f, "%lf\n", pitem->weight);
    fprintf(f, "%lf\n", pitem->volume);
}
