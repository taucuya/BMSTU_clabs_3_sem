#include "sort.h"

int comp_int(const void *first, const void *second)
{
    const int *a = first;
    const int *b = second;
    return *a - *b;
}
 
int comp_double(const void *first, const void *second)
{
    const double *a = first;
    const double *b = second;
    if ((*a - *b - EPS) > 0)
        return 1;
    else
        return 0;
}

int comp_string(const void *first, const void *second)
{
    const char *a = first;
    const char *b = second;
    return *a - *b;
}

void mysort(void *beg, int number, size_t size, int (*compare)(const void *, const void *))
{
    char *el;
    char *loc;
    char *pbeg = beg;
    char *end = (char *) beg + number * size;
    for (char *i = pbeg + size; i < end; i += size)
    {
        el = i;
        char tmp[size];
        memcpy(tmp, el, size);
        loc = i - size;
        while (loc >= pbeg && compare((const void *) loc, (const void *) tmp) > 0)
        {
            memcpy(loc + size, loc, size);
            loc -= size;
        }
        memcpy(loc + size, tmp, size);
    }
}
