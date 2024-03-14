#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct number
{
    int divider;
    int degree;
    struct number *next;
} num_t;


#endif