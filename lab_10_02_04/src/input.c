#include "input.h"

int input()
{
    char command[4];
    if (scanf("%s", command) != 1)
    {
        return ERR_COMM_INP;
    }
    if (strcmp(command, "out") == 0)
    {
        int num;
        num_t *head = NULL;
        if (scanf("%d", &num) != 1)
        {
            return ERR_NUM_READ;
        }
        if (num == 0)
        {
            return ERR_NULL;
        }
        make_list(&head, num);
        print_list(&head);
        free_list(&head);
    }
    else if (strcmp(command, "mul") == 0)
    {
        int num1, num2;
        num_t *head1 = NULL, *head2 = NULL, *head_res = NULL;
        if (scanf("%d", &num1) != 1)
        {
            return ERR_NUM_READ;
        }
        if (scanf("%d", &num2) != 1)
        {
            return ERR_NUM_READ;
        }
        if (num1 == 0 || num2 == 0)
        {
            return ERR_NULL;
        }
        make_list(&head1, num1);
        make_list(&head2, num2);
        multiply(&head1, &head2, &head_res);
        free_list(&head1);
        free_list(&head2); 
        print_list(&head_res);
        free_list(&head_res);
    }
    else if (strcmp(command, "sqr") == 0)
    {
        int num;
        num_t *head = NULL, *head_res = NULL;
        if (scanf("%d", &num) != 1)
        {
            return ERR_NUM_READ;
        }
        if (num == 0)
        {
            return ERR_NULL;
        }
        make_list(&head, num);
        multiply(&head, &head, &head_res);
        free_list(&head);
        print_list(&head_res);
        free_list(&head_res);
    }
    else if (strcmp(command, "div") == 0)
    {
        int num1, num2;
        num_t *head1 = NULL, *head2 = NULL, *head_res = NULL;
        if (scanf("%d", &num1) != 1)
        {
            return ERR_NUM_READ;
        }
        if (scanf("%d", &num2) != 1)
        {
            return ERR_NUM_READ;
        }
        if (num1 == 0 || num2 == 0)
        {
            return ERR_NULL;
        }
        make_list(&head1, num1);
        make_list(&head2, num2);
        division(&head1, &head2, &head_res);
        free_list(&head1);
        free_list(&head2);
        print_list(&head_res);
        free_list(&head_res);
    }
    else 
    {
        return ERR_WRONG_COMMAND;
    }
    return SUCCESS;
}