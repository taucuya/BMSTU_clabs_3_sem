#include "act.h"

void make_list(num_t **head, int num)
{
    int div = 2;
    while (num != 1)
    {
        int cnt = 0;
        while (num % div == 0)
        {
            cnt++;
            num /= div;
        }
        if (cnt)
        {
            num_t *number = create_node(div, cnt);
            list_add(head, number);
        }
        div++;
    }
}

void multiply(num_t **head1, num_t **head2, num_t **head_res)
{
    int num1 = make_num(head1);
    int num2 = make_num(head2);
    int res = num1 * num2;
    make_list(head_res, res);
}

void division(num_t **head1, num_t **head2, num_t **head_res)
{
    int num1 = make_num(head1);
    int num2 = make_num(head2);
    int res = num1 / num2;
    make_list(head_res, res);
}

int make_num(num_t **head)
{
    num_t *cur = *head;
    int final = 1;
    while (cur)
    {
        int num = cur->divider;
        for (int i = 1; i < cur->degree; i++)
        {
            num *= cur->divider;
        }
        final *= num;
        cur = cur->next;
    }
    return final;
}