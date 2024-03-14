#include "../inc/filter.h"


int key(const int *mas, const int *end, int **new_beg, int **new_end)
{
    if (mas == NULL || end == NULL || end <= mas || new_beg == NULL || new_end == NULL)
        return ERR_KEY;

    int sum = *(end - 1);
    int cnt = 0;
    
    for (int *i = (int *) end - 2; i > mas - 1; i--)
    {
        if (*i > sum)
            cnt++;
        sum += *i;
    }
    if (!cnt)
        return ERR_EMPTY_FILTER;
        
    // if (!(*new_beg = calloc(cnt, sizeof(int))))
    //     return ERR_ALLOCATION;

    *new_end = *new_beg + cnt;
    int *loc = *new_end - 1;
    sum = *(end - 1);
    for (int *i = (int *) end - 2; i > mas - 1; i--)
    {
        if (*i > sum)
        {
            *loc = *i;
            loc--;
        }
        sum += *i;
    }
    
    return SUCCESS;
}
