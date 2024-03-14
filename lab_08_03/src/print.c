#include "print.h"

void print(int *first, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", first[i * n + j]);
        }
        printf("\n");
    }
}