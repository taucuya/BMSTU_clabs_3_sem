#ifndef _ACT_H_
#define _ACT_H_

#include "gen.h"
#include "list.h"

void make_list(num_t **head, int num);
int make_num(num_t **head);
void multiply(num_t **head1, num_t **head2, num_t **head_res);
void division(num_t **head1, num_t **head2, num_t **head_res);

#endif