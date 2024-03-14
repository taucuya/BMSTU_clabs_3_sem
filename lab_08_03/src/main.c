#include "input.h"
#include "make_square.h"
#include "print.h"
#include "add.h"
#include "multiply.h"
#include "allocate.h"

int main()
{
    int m, n;
    int p, q;
    if (scanf("%d%d", &m, &n) != 2)
    {
        return ERR_DIMENT_INP;
    }
    
    if (m < 1 || n < 1)
    {
        return ERR_DIMENT_INP;
    }
    int **first = allocate_matrix(m, n);

    if (!first)
    {
        return ERR_ALLOC;
    }

    int rc = input(first[0], m, n);
    if (rc)
    {
        free(first[0]);
        free(first);
        return rc;
    }
    if (scanf("%d%d", &p, &q) != 2)
    {
        free(first[0]);
        free(first);
        return ERR_DIMENT_INP;
    }

    if (p < 1 || q < 1)
    {
        free(first[0]);
        free(first);
        return ERR_DIMENT_INP;
    }

    int **second = allocate_matrix(p, q);

    if (!second)
    {
        free(first[0]);
        free(first);
        return ERR_ALLOC;
    }

    rc = input(second[0], p, q);
    if (rc)
    {
        free(first[0]);
        free(first);
        free(second[0]);
        free(second);
        return rc;
    }
    rebuild_to_square(first[0], &m, &n);
    rebuild_to_square(second[0], &p, &q);

    size_t final;
    if (n > p)
        final = n;
    else 
        final = p;
    
    int **one = realloc_matrix(first[0], n, final);
    if (!one)
    {
        free(first[0]);
        free(first);
        free(second[0]);
        free(second);
        return ERR_ALLOC;
    }
    int **two = realloc_matrix(second[0], p, final);
    
    if (!two)
    {
        free(one[0]);
        free(one);
        free(first[0]);
        free(first);
        free(second[0]);
        free(second);
        return ERR_ALLOC;
    }

    free(first[0]);
    free(first);
    free(second[0]);
    free(second);
    
    rebuild(one[0], final, n);
    rebuild(two[0], final, p);

    int **result = allocate_matrix(final, final);
    if (!result)
    {
        free(one[0]);
        free(one);
        free(two[0]);
        free(two);
        return ERR_ALLOC;
    }

    if (make_result(one[0], two[0], result[0], final))
    {
        free(one[0]);
        free(one);
        free(two[0]);
        free(two);
        free(result[0]);
        free(result);
        return ERR_FIN_INP;
    }

    print(result[0], final, final);
    free(one[0]);
    free(one);
    free(two[0]);
    free(two);
    free(result[0]);
    free(result);
    return SUCCESS;
}