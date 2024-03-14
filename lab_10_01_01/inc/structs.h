#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct 
{
    char item[100];
    int price;
} product;


typedef struct node node_t;

struct node 
{
    void *data;
    node_t *next;
};

typedef struct 
{
    product *mas;
    int len;
} vec;


#endif