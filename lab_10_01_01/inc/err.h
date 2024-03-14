#ifndef _ERR_H_
#define _ERR_H_

#define SUCCESS 0

#define ERR_ALLOC 1

// Errors with file reading

#define ERR_OPEN_FILE 2
#define ERR_EMPTY_FILE 3
#define ERR_READ_ITEM 4
#define ERR_READ_PRICE 5


// Errors in command line 

#define ERR_COMMAND 10

// Equivalence

#define LISTS_NOT_EQUAL 6
#define LISTS_EQUAL 7

// Comparator returns

#define OK 1
#define NE_OK -1


#endif