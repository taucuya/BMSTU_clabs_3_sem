#include "item_arr.h"

int itemarr_read(FILE *f, itm **pitems, int n_max) 
{
    itm *temp = NULL;
    temp = malloc(ITEM_SIZE);
    if (!temp)
    {
        return ERR_ALLOC;
    }
    int rc = ERR_OK;
    int i = 0;
    while (rc == ERR_OK) 
    {
        rc = item_read(f, temp);
        if (rc == ERR_OK) 
        {
            if (i < n_max) 
            {
                (*pitems + i)->name = temp->name;
                (*pitems + i)->volume = temp->volume;
                (*pitems + i)->weight = temp->weight;
                i++;
                free(temp);
                temp = malloc(ITEM_SIZE);
                if (!temp)
                {
                    return ERR_ALLOC;
                }
            }
            else
            {
                free(temp->name);
                free(temp);
                rc = ERR_OVERFLOW;
            }                
        }
        else if (rc != ERR_OK && i == 0)
        {
            free(temp);
            rc = ERR_EMPTYFILE;
        }
        else if (rc == ERR_IO && i != 0)
        {
            if (!feof(f))
            {
                rc = ERR_IO;
            }
            else
            {
                rc = FINAL;
            }
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    if (rc == FINAL)
        rc = ERR_OK;
    return rc;
}

void itemarr_print(FILE *f, itm **pitems, int n) 
{
    for (int i = 0; i < n; i++)
    {
        item_print(f, *pitems + i);
    }
}

int count(FILE *f, int n_max, int *n)
{
    itm *temp = NULL;
    temp = malloc(ITEM_SIZE);
    if (!temp)
    {
        return ERR_ALLOC;
    }
    int rc = ERR_OK;
    int i = 0;
    while (rc == ERR_OK) 
    {
        rc = item_read(f, temp);

        if (rc == ERR_OK) 
        {
            if (i < n_max) 
            {
                i++;
                free(temp->name);
                free(temp);
                temp = malloc(ITEM_SIZE);
                if (!temp)
                {
                    return ERR_ALLOC;
                }
            }
            else
            {
                free(temp->name);
                free(temp);
                rc = ERR_OVERFLOW;
            }                
        }
        else if (rc != ERR_OK && i == 0)
        {
            free(temp);
            rc = ERR_EMPTYFILE;
        }
        else if (rc == ERR_IO && i != 0)
        {
            if (!feof(f))
            {
                rc = ERR_IO;
            }
            else
            {
                rc = FINAL;
            }
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    if (rc == FINAL)
        rc = ERR_OK;
    *n = i;
    return rc;
}