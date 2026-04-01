#include "grains.h"
uint64_t square(uint8_t index)
{
    uint64_t num = 1;
    
    if(index >= 1 && index < 65)
        return num << (index-1);
    else
        return 0;
}
uint64_t total(void)
{
    uint64_t sum = 0;
    for(uint8_t i =1; i <= 64 ; i++) sum += square(i);
    return sum;
}