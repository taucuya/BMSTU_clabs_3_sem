#include "input.h"

int input(int *first, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (scanf("%d", &first[i * n + j]) != 1)
                return ERR_FMATR_EL_INP;
        }
    }
    return SUCCESS;
}