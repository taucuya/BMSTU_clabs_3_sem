#include "sort.h"

void sort(itm *pitems, int n) 
{
    itm temp;
    for (int i = 0; i < (n - 1); i++) 
    {
        for (int j = 0; j < (n - i - 1); j++) 
        {
            if (((pitems + j)->weight) / ((pitems + j)->volume) - (((pitems + j + 1)->weight) / ((pitems + j + 1)->volume)) > EPS) 
            {
                temp = pitems[j];
                pitems[j] = pitems[j + 1];
                pitems[j + 1] = temp;                
            }
        }
    }
}