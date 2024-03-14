#include <string.h>
#include <stdio.h>
#include "item.h"

int item_read(FILE *f, itm *pitem) 
{
    char buf[NAME_LEN + 10];
    int len;
    double weight;
    double volume;

    if (!fgets(buf, sizeof(buf), f))
        return ERR_IO;
    len = strlen(buf);
    if (!len || len > (NAME_LEN + 1) || len == 1)
    {
        return ERR_DATA;
    }
    if (len && buf[len - 1] == '\n') 
    {
        buf[len - 1] = '\0';
        len --;
    }
    char sign;
    int check1 = fscanf(f, "%lf%c", &weight, &sign);
    if (check1 == 0 || check1 == -1 || (check1 == 2 && sign != '\n') || weight <= 0)
        return ERR_DATA;

    int check2 = fscanf(f, "%lf%c", &volume, &sign);
    if (check2 == 0 || check2 == -1 || (check2 == 2 && sign != '\n') || volume <= 0)
        return ERR_DATA;

    strcpy(pitem->name, buf);
    pitem->weight = weight;
    pitem->volume = volume;

    return ERR_OK;    
}

void item_print(FILE *f, const itm *pitem) 
{
    fprintf(f, "%s\n", pitem->name);
    fprintf(f, "%lf\n", pitem->weight);
    fprintf(f, "%lf\n", pitem->volume);
}
