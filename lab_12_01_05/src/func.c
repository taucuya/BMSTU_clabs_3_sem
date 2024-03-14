#include "../inc/func.h"

int counter(const char *file, int *n)
{
    FILE *f = fopen(file, "r");
    if (!f)
    {
        return ERR_FILE_OPEN;
    }
    int tmp;
    while (fscanf(f, "%d", &tmp) == 1)
    {
        (*n)++;
    }
    if (!feof(f))
    {
        fclose(f);
        return ERR_DATA;
    }
    if (!(*n))
    {
        fclose(f);
        return ERR_EMPTY_FILE;
    }
    fclose(f);
    return SUCCESS;
}

void fill(const char *file, int *mas)
{
    FILE *f = fopen(file, "r");
    while (fscanf(f, "%d", mas) == 1)
    {
        mas++;
    }
    fclose(f);
}