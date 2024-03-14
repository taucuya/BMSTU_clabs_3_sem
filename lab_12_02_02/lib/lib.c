#include "lib.h"
#include <stdlib.h>

void fib(int *arr, int n)
{
    int fib_1 = 0;
    int fib_2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            arr[i] = fib_1;
        else if (i == 1)
            arr[i] = fib_2;
        else
        {
            int new_fib = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = new_fib;
            arr[i] = new_fib;
        }
    }
}

bool first_occurance(int *nums, int size, int num)
{
    for (size_t i = 0; (size_t) i < size; ++i)
    {
        if (nums[i] == num)
        {
            return false;
        }
    }
    return true;
}

int first_entry(int *src, int src_size, int *dest, int *dest_size)
{
    /* Handle error cases */
    if (src == NULL)
    {
        return 1; 
    }
    if (src_size <= 0)
    {
        return 1;
    }

    bool must_write = true;
    int *temp = NULL;
    if (dest == NULL)
    {
        must_write = false;
        temp = malloc(src_size * sizeof(int));
    }

    /* Perform filtering */
    int counter = 0; 
    for (size_t i = 0; i < (size_t) src_size; ++i)
    {
        if (must_write == true)
        {
            if (first_occurance(dest, counter, src[i]))
            {
                dest[counter] = src[i];
                counter++; 
            }
        }
        else
        {
            if (first_occurance(temp, counter, src[i]))
            {
                temp[counter] = src[i];
                counter++;
            }
        }
    }
    if (temp != NULL)
    {
        free(temp);
    }

    *dest_size = counter; 
    return 0;
}