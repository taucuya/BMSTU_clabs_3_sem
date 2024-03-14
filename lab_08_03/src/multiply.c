#include "multiply.h"


void copy(int *src, int *dst, size_t final)
{
    for (size_t i = 0; i < final; i++)
    {
        for (size_t j = 0; j < final; j++)
        {
            dst[final * i + j] = src[final * i + j];
        }
    }
}

int make_result(int *first, int *second, int *result, size_t final)
{
    int p, q;
    if (scanf("%d%d", &p, &q) != 2)
        return ERR_FIN_INP;
    if (p < 0 || q < 0)
        return ERR_FIN_INP;
    if (p == 0)
    {
        for (size_t i = 0; i < final; i++)
        {
            for (size_t j = 0; j < final; j++)
            {
                if (i == j)
                {
                    result[final * i + j] = 1;
                }
            }
        }
    }
    else
    {
        int **temp = allocate_matrix(final, final);
        if (!temp)
        {
            return ERR_ALLOC;
        }
        copy(first, result, final);

        for (int i = 1; i < p; i++)
        {
            multiply(temp[0], result, first, final);
            copy(temp[0], result, final);
            make_zeroes(temp[0], final);
        }
        free(temp[0]);
        free(temp);
    }
    int **res = allocate_matrix(final, final);
    if (!res)
    {
        return ERR_ALLOC;
    }
    if (q == 0)
    {
        int **temp = allocate_matrix(final, final);
        if (!temp)
        {
            free(res[0]);
            free(res);
            return ERR_ALLOC;
        }
        for (size_t i = 0; i < final; i++)
        {
            for (size_t j = 0; j < final; j++)
            {
                if (i == j)
                {
                    temp[0][i * final + j] = 1;
                }
            }
        }
        multiply(res[0], result, temp[0], final);
        free(temp[0]);
        free(temp);
    } 
    else
    {
        for (int h = 0; h < q; h++)
        {
            multiply(res[0], result, second, final);
            copy(res[0], result, final);
            make_zeroes(res[0], final);
        }
    }
    free(res[0]);
    free(res);
    return SUCCESS;
}


void make_zeroes(int *res, size_t final)
{
    for (size_t i = 0; i < final; i++)
    {
        for (size_t j = 0; j < final; j++)
        {
            res[i * final + j] = 0;
        }
    }
}