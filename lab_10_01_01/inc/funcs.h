#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "gen.h"

int comparator_price(const void *head, const void *data);
node_t *create_node(node_t **head, product *data);
void append(node_t **head_a, node_t **head_b);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void *pop_back(node_t **head);
void list_free(node_t **head);
void *pop_front(node_t **head);
int cmp(node_t **head1, node_t **head2);
node_t *init_node(product *data);

#endif