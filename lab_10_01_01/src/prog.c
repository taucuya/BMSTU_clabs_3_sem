#include "prog.h"

void proc(char **uniq, int uniq_num, vec *products)
{
    node_t *head1 = NULL;
    for (int j = 0; j < products->len; j++)
    {
        if (!strcmp(uniq[0], products->mas[j].item))
            head1 = create_node(&head1, &products->mas[j]);
    }
    head1 = sort(head1, comparator_price);
    node_t *cur = head1;
    int cnt = 0;
    while (cur)
    {
        cur = cur->next;
        cnt++;
    }
    if (cnt != 1)
        pop_back(&head1);
    for (int i = 1; i < uniq_num; i++)
    {
        node_t *head2 = NULL;
        for (int j = 0; j < products->len; j++)
        {
            if (!strcmp(uniq[i], products->mas[j].item))
                head2 = create_node(&head2, &products->mas[j]);
        }
        head2 = sort(head2, comparator_price);
        node_t *cur1 = head2;
        int cnt = 0;
        while (cur1)
        {
            cur1 = cur1->next;
            cnt++;
        }
        if (cnt != 1)
            pop_back(&head2);
        append(&head1, &head2);
    }
    node_t *cur2 = head1;
    while (cur2)
    {
        product p = *(product *)(cur2->data);
        printf("%s %d\n", p.item, p.price);
        cur2 = cur2->next;
    }
    list_free(&head1);
}