#include "add.h"

void rebuild(int *first, size_t final, size_t size)
{
    if (final > size)
    {
        size_t size_1 = size;
        while (size_1 < final)
        {
            add_rows(first, size_1, size);
            size_1++;
        }
        while (size < final)
        {
            add_columns(first, final, size);
            size++;
        }
    }
}

void add_rows(int *first, size_t size_1, size_t size)
{
    int sum;
    for (size_t i = 0; i < size; i++)
    {
        sum = 0;
        for (size_t j = 0; j < size_1; j++)
        {
            sum += first[j * size + i];
        }
        first[size * size_1 + i] = sum / size_1;
    }
}

void add_columns(int *first, size_t final, size_t size)
{
    int max;
    int tmp;
    for (size_t i = 0; i < final; i++)
    {
        max = first[i * size + i];
        for (size_t j = 0; j < size; j++)
        {
            if (max < first[i * size + j + i])
            {
                max = first[i * size + j + i];
            }
        }
        first[final * size + i] = max;
        for (size_t j = (final * size + i); j > (size * (1 + i) + i); j--)
        {
            tmp = first[j - 1];
            first[j - 1] = first[j];
            first[j] = tmp;
        }
    }
}