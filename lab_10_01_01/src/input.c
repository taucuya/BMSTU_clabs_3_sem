#include "input.h"

int read_from_file(char *filename, vec *products, char **uniq, int *uniq_num)
{
    FILE *f = fopen(filename, "r");

    if (!f)
    {
        return ERR_OPEN_FILE;
    }
    char sign = fgetc(f);
    if (sign == EOF)
    {
        fclose(f);
        return ERR_EMPTY_FILE;
    }
    rewind(f);
    int t;
    char tmp[101];

    while (!feof(f))
    {
        if (!fgets(tmp, 101, f))
        {
            fclose(f);
            return ERR_READ_ITEM;
        }
        tmp[strlen(tmp) - 1] = '\0';
        if (fscanf(f, "%d\n", &t) != 1)
        {
            fclose(f);
            return ERR_READ_PRICE;
        }
        if (t < 1)
        {
            fclose(f);
            return ERR_READ_PRICE;
        }
        strcpy(products->mas[products->len].item, tmp);
        products->mas[products->len].price = t;
        products->len++;
    }
    fclose(f);
    strcpy(uniq[0], products->mas[0].item);
    (*uniq_num) = 1;
    for (int i = 1; i < products->len; i++)
    {
        int cnt = 0;
        for (int j = 0; j < *uniq_num; j++)
        {
            if (!strcmp(uniq[j], products->mas[i].item))
            {
                cnt++;
                break;
            }
        }
        if (!cnt)
        {
            strcpy(uniq[*uniq_num], products->mas[i].item);
            (*uniq_num)++;
        }
    }
    return SUCCESS;
}

int count_structs(char *filename, int *num)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return ERR_OPEN_FILE;
    }
    char sign = fgetc(f);
    if (sign == EOF)
    {
        fclose(f);
        return ERR_EMPTY_FILE;
    }
    rewind(f);
    char tmp[101];
    int t;

    while (!feof(f))
    {
        if (!fgets(tmp, 101, f))
        {
            fclose(f);
            return ERR_READ_ITEM;
        }
        tmp[strlen(tmp) - 1] = '\0';
        if (fscanf(f, "%d\n", &t) != 1)
        {
            fclose(f);
            return ERR_READ_PRICE;
        }
        (*num)++;
    }
    fclose(f);
    return SUCCESS;
}