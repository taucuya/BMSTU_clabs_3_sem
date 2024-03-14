#include "input.h"
#include "prog.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return ERR_COMMAND;
    }
    int num = 0;
    int rc = count_structs(argv[1], &num);
    if (rc)
    {
        return rc;
    }
    vec products = { 0 };
    products.mas = (product *) malloc(sizeof(product) * num);
    char **uniq = (char **) malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++)
    {
        uniq[i] = (char *) malloc(100 * sizeof(char));
    }
    int uniq_num;
    int rc2 = read_from_file(argv[1], &products, uniq, &uniq_num);
    if (rc2)
    {
        for (int i = 0; i < uniq_num; i++)
        {
            free(uniq[i]);
        }
        free(uniq);
        free(products.mas);
        return rc2;
    }
    proc(uniq, uniq_num, &products);
    for (int i = 0; i < num; i++)
    {
        free(uniq[i]);
    }
    free(uniq);
    free(products.mas);

    return SUCCESS;
}