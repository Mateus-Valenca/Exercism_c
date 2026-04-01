#include "reverse_string.h"
char *reverse(const char *value)
{
    int len = strlen(value);
    char *rev = malloc(len + 1);
    if (rev == NULL)
        return NULL;

    for (int i = 0; i < len; i++)
    {
        rev[i] = value[len - 1 - i];
    }

    rev[len] = '\0';

    return rev;
}