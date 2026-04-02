#include "leap.h"
bool leap_year(int year)
{
    bool leap = false;
    if(year % 100 == 0)
    {
        if(year % 400 == 0) leap = true;
    }
    else if(year % 4 == 0) leap = true;
    return leap;
        
}