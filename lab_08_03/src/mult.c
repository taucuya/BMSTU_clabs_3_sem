#include "mult.h"

void multiply(int *result, int *first, int *second, size_t final)
{
    for (size_t i = 0; i < final; i++)
    {
        for (size_t j = 0; j < final; j++)
        {
            for (size_t k = 0; k < final; k++)
            {
                result[i * final + j] += first[i * final + k] * second[k * final + j];
            }
        }
    }
}