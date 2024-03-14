#include "funcs.h"

node_t *create_node(node_t **head, product *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->data = data;
        node->next = *head;
    }
    return node;
}

int comparator_price(const void *first, const void *second)
{
    product prod2 = *(product *) second;
    product prod1 = *(product *) first;
    if (prod1.price > prod2.price)
        return OK;
    else if (prod1.price < prod2.price)
        return NE_OK;
    return SUCCESS;
}

void *pop_back(node_t **head)
{
    void *data_ptr = NULL;
    if (!head || !(*head))
        return data_ptr;
    node_t *pre_end = *head;
    data_ptr = pre_end->data;
    if (!pre_end->next)
    {
        free(pre_end);
        *head = NULL;
        return data_ptr;
    }
    node_t *end = pre_end->next;  
    while (end->next)
    {
        pre_end = end;
        end = end->next;
    }
    data_ptr = end->data; 
    pre_end->next = NULL;
    free(end);
    return data_ptr;
}

void append(node_t **head_a, node_t **head_b)
{
    node_t *placer = *head_a;
    if (placer)
    {
        while (placer->next)
        {
            placer = placer->next;
        }
    }

    if (placer == NULL && *head_b != NULL)
    {
        void *scanned_data = pop_front(head_b);
        *head_a = init_node(scanned_data);
        placer = *head_a;
    }

    while (*head_b)
    {
        void *scanned_data = pop_front(head_b);

        node_t *new_node = init_node(scanned_data);

        placer->next = new_node;
        placer = placer->next;
    }
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *cur = *head;
    node_t *prev = NULL;
    
    if (*head == NULL)
    {
        *head = element;
        return;
    }
    while (cur != NULL && comparator(cur->data, element->data) < 0)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL)
    {
        prev->next = element;
    }
    else
    {
        *head = element; 
    }
    element->next = cur;
}

void *pop_front(node_t **head)
{
    void *data_ptr = NULL;
    if (!head || !(*head))
    {
        return data_ptr;
    }
    data_ptr = (*head)->data;
    node_t *front_node = *head;
    *head = (*head)->next;
    free(front_node);

    return data_ptr;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *n_head = NULL;
    while (head != NULL)
    {
        void *cur_data = pop_front(&head);
        node_t *new_node = init_node(cur_data);
        sorted_insert(&n_head, new_node, comparator);
    }
    return n_head;
}

void list_free(node_t **head)
{
    if (*head == NULL) 
        return;
    node_t *cur = *head; 
    node_t *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    } 
}


int cmp(node_t **head1, node_t **head2)
{
    node_t *cur1 = *head1;
    node_t *cur2 = *head2;

    while (cur1 && cur2)
    {
        if (cur1->data != cur2->data)
        {
            return LISTS_NOT_EQUAL;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    } 
    if (!cur1 && !cur2)
    {
        return LISTS_EQUAL;
    }
    return LISTS_NOT_EQUAL;
}

node_t *init_node(product *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}