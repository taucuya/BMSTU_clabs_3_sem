#include "../inc/err.h"
#include "../inc/func.h"
#include "../inc/filter.h"
#include "../inc/sort.h"
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        return ERR_COMMAND;

    int n = 0;
    int *pn = &n;
    int *mas;

    void *dll = dlopen("libraries/dyn_lib_2/dyn_lib_2.so", RTLD_NOW);
    if (!dll)
    {
        return 7856;
    }

    int (*counter)(const char *file, int *n) = dlsym(dll, "counter");
    int (*fill)(const char *file, int *mas) = dlsym(dll, "fill");

    int (*key)(const int *mas, const int *end, int **new_beg, int **new_end) = dlsym(dll, "key");

    int (*comp_int)(const void *, const void *) = dlsym(dll, "comp_int");
    void (*mysort)(void *beg, int number, size_t size, int (*compare)(const void *, const void *)) = dlsym(dll, "mysort");

    int check = counter(argv[1], pn);
    if (check)
    {
        return check;
    }
    if (!(mas = calloc(n, sizeof(int))))
        return ERR_ALLOCATION;
    int *end = mas + n;
    fill(argv[1], mas);
    if (argc == 4 && strcmp(argv[3], "f"))
    {
        free(mas);
        return ERR_COMMAND;
    }
    else if (argc == 4 && !strcmp(argv[3], "f"))
    {
        int *new_beg, *new_end;
        if (!(new_beg = (int *) calloc(MAX_SIZE, sizeof(int))))
            return ERR_ALLOCATION;
        int rc = key(mas, end, &new_beg, &new_end);
        free(mas);
        if (rc)
        {
            return rc;
        }
        n = new_end - new_beg;
        mysort(new_beg, n, sizeof(int), comp_int);
        FILE *f = fopen(argv[2], "w");
        for (int *i = new_beg; i < new_end; i++)
        {
            fprintf(f, "%d%c", *i, (i == new_end - 1) ? '\n' : ' ');
        }
        fclose(f);
        free(new_beg);
    }
    else if (argc == 3)
    {
        mysort(mas, n, sizeof(int), comp_int);
        FILE *f = fopen(argv[2], "w");
        for (int *i = mas; i < end; i++)
        {
            fprintf(f, "%d%c", *i, (i == end - 1) ? '\n' : ' ');
        }
        fclose(f);
        free(mas);
    }
    return SUCCESS;
}
