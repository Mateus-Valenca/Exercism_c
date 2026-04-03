#include "eliuds_eggs.h"


unsigned int egg_count(unsigned int number)
{
    unsigned int count = 0;
    while(number != 0)
    {
        if( number & (1 << 0)) count++;
        
        number = number >> 1;
    }
    return count;
}