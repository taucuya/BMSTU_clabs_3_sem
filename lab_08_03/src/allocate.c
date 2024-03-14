#include "allocate.h"

int **allocate_matrix(int n, int m)
{
    int **ptrs, *data;
    ptrs = calloc(n, sizeof(int *));
    if (!ptrs)
        return NULL;
    data = calloc(n * m, sizeof(int));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        ptrs[i] = data + i * m;
    }
    return ptrs;
}

int **realloc_matrix(int *first, int size, int n)
{
    int **ptrs, *data;
    ptrs = calloc(n, sizeof(int *));
    if (!ptrs)
        return NULL;
    data = calloc(n * n, sizeof(int));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        ptrs[i] = data + i * n;
    }
    for (int i = 0; i < size * size; i++)
    {
        ptrs[0][i] = first[i];
    }
    if (size != n)
    {
        for (int i = size * size; i < n * n; i++)
        {
            ptrs[0][i] = 0;
        }
    }
    return ptrs;
}
