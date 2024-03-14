#include "list.h"

num_t *create_node(int div, int deg)
{
    num_t *number = malloc(sizeof(num_t));

    if (number)
    {
        number->divider = div;
        number->degree = deg;
        number->next = NULL;
    }

    return number;
}

void list_add(num_t **head, num_t *number)
{
    number->next = *head;
    *head = number;
}

void print_list(num_t **head)
{
    num_t *cur = *head;
    while (cur)
    {
        printf("%d %d ", cur->divider, cur->degree);
        cur = cur->next;
    }
    printf("1\n");
}

void free_list(num_t **head)
{
    num_t *cur = *head; 
    num_t *next = NULL;

    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    } 
}

int compare(num_t **head1, num_t **head2)
{
    num_t *cur1 = *head1;
    num_t *cur2 = *head2;

    while (cur1 && cur2)
    {
        if (cur1->degree != cur2->degree)
        {
            return ERR_NOT_SAME;
        }
        if (cur1->divider != cur2->divider)
        {
            return ERR_NOT_SAME;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    } 
    if (!cur1 && !cur2)
    {
        return SUCCESS;
    }
    return ERR_NOT_SAME;
}