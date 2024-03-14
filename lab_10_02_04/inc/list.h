#ifndef _LIST_H_
#define _LIST_H_

#include "gen.h"
#include "act.h"

num_t *create_node(int div, int deg);
void list_add(num_t **head, num_t *number);
void print_list(num_t **head);
void free_list(num_t **head);
int compare(num_t **head1, num_t **head2);

#endif