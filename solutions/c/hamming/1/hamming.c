#include "hamming.h"
int compute(const char *lhs, const char *rhs)
{
    int i = 0, hamming_distance = 0;
    while(lhs[i] != '\0' && rhs[i] != '\0')
    {
        if(lhs[i] != rhs[i]) hamming_distance++;
        i++;
    }
    if(lhs[i] != '\0' || rhs[i] != '\0') return ERROR_VALUE;
    return hamming_distance;
}
