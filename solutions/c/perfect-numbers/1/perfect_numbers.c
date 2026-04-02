#include "perfect_numbers.h"


kind classify_number(int number)
{
    int sum=0;
    if(number <= 0) return ERROR;
    if(number == 1) return DEFICIENT_NUMBER;
    for(int i = 1; i < number; i++)
    {
        if(number % i == 0) sum+=i; 
    }
    if(sum == number) return PERFECT_NUMBER;
    else if (sum > number) return ABUNDANT_NUMBER;
    else return DEFICIENT_NUMBER;
    
}