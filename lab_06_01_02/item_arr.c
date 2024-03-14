#include "item_arr.h"

int itemarr_read(FILE *f, itm *pitems, int n_max, int *n) 
{
    itm temp;
    int rc = ERR_OK;
    int i = 0;
    while (rc == ERR_OK) 
    {
        rc = item_read(f, &temp);
        if (rc == ERR_OK) 
        {
            if (i < n_max) 
            { 
                pitems[i] = temp;
                i++;
            }
            else if (rc != ERR_IO) 
            {
                rc = ERR_OVERFLOW;
            }                
        }
        else if (rc != ERR_OK && i == 0)
            rc = ERR_EMPTYFILE;
        else if (rc == ERR_IO && i != 0)
            rc = FINAL;
    }
    if (rc == FINAL)
        rc = ERR_OK;
    *n = i;
    return rc;
}

void itemarr_print(FILE *f, const itm *pitems, int n) 
{
    for (int i = 0; i < n; i++)
        item_print(f, pitems + i);
}

void sort(itm *pitems, int n) 
{
    itm temp;
    for (int i = 0; i < (n - 1); i++) 
    {
        for (int j = 0; j < (n - i - 1); j++) 
        {
            if (((pitems + j)->weight) / ((pitems + j)->volume) - (((pitems + j + 1)->weight) / ((pitems + j + 1)->volume)) > EPS) 
            {
                temp = pitems[j];
                pitems[j] = pitems[j + 1];
                pitems[j + 1] = temp;                
            }
        }
    }
}