#include "make_square.h"

void find_max(int *first, int m, int n, int *max_i, int *max_j)
{
    *max_i = 0;
    *max_j = 0;
    int max = first[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (first[j * n + i] > max)
            {
                max = first[j * n + i];
                *max_i = i;
                *max_j = j;
            }
        }
    }
}

void rebuild_to_square(int *first, int *m, int *n)
{
    int max_i;
    int max_j;
    if (*m > *n)
    {
        while (*m != *n)
        {
            find_max(first, *m, *n, &max_i, &max_j);
            delete_row(first, max_j, *m, *n);
            *m -= 1;
        }
    }
    if (*n > *m)
    {
        while (*n != *m)
        {
            find_max(first, *m, *n, &max_i, &max_j);
            delete_column(first, max_i, *m, *n);
            *n -= 1;
        }
    }
}

void delete_row(int *first, int row, int m, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n * row; j < m * n - 1; j++)
        {
            tmp = first[j];
            first[j] = first[j + 1];
            first[j + 1] = tmp;
        }
    }
}

void delete_column(int *first, int column, int m, int n)
{
    int tmp = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i * n + column - i; j < m * n - 1; j++)
        {
            tmp = first[j];
            first[j] = first[j + 1];
            first[j + 1] = tmp;
        }
    }
}