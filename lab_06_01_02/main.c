#include <stdio.h>
#include <string.h>
#include "error.h"
#include "item_arr.h"

void show_message(int rc) 
{
    printf("ERROR!\n");
    switch (rc) 
    {
        case ERR_IO:
            printf("INPUT ERROR\n");
            break;
        case ERR_DATA:
            printf("INCORRECT DATA\n");
            break;
        case ERR_OVERFLOW:
            printf("ARRAY OVERFLOW\n");
            break;
        case ERR_FILE:
            printf("FILE IS NOT OPENED\n");
            break;
        case ERR_COMMAND:
            printf("SOME PROBLEMS WITH COMMAND LINE\n");
            break;
        case ERR_NOMATCH:
            printf("NO SUBSTRING MATCHES\n");
            break;
        case ERR_EMPTYFILE:
            printf("EMPTY FILE OR FILE WITH WRONG DATA\n");
            break;
    }
}


int main(int arg, char *argv[]) 
{
    FILE *f;
    itm items[N_MAX];
    int n_items = 0;
    int rc;
    if (arg != 2 && arg != 3)
    {
        rc = ERR_COMMAND;
        show_message(rc);
        return rc;
    }
    f = fopen(argv[1], "r");
    if (f) 
    {
        rc = itemarr_read(f, items, N_MAX, &n_items);
        if (rc == ERR_OK && arg == 2) 
        {
            sort(items, n_items);
            itemarr_print(stdout, items, n_items);
            fclose(f);
        }
        else if (rc == ERR_OK && arg == 3) 
        {
            if (!strcmp("ALL", argv[2])) 
            {
                itemarr_print(stdout, items, n_items);
            }
            else 
            {
                int cnt = 0;
                for (int i = 0; i < n_items; i++) 
                {
                    if (strstr(items[i].name, argv[2]) == items[i].name) 
                    {
                        printf("%s\n%lf\n%lf\n", items[i].name, items[i].weight, items[i].volume);
                        cnt++;
                    }
                }
                if (cnt == 0) 
                {
                    rc = ERR_NOMATCH;
                    show_message(rc);
                }
            }
            fclose(f);
        }
        else 
            show_message(rc);
    }
    else 
    {
        rc = ERR_FILE;
        show_message(rc);
    }
    return rc;
}