#include "binary.h"

int convert(const char *input)
{
    int power = strlen(input) - 1;
    int decimal_num = 0;
    for(int i = 0; i <= power; i++)
    {
        if(input[i] != '1' && input[i] != '0') return INVALID;
        if(input[i] == '1') decimal_num += (1 << (power -i));
    }
    return decimal_num;
}