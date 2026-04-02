#include "secret_handshake.h"




const char **commands(size_t number)
{
    const char **result = malloc(5 * sizeof(char*)); // 4 actions + NULL
    if (!result) return NULL;
    // Initialize ALL slots to NULL
    for (int i = 0; i < 4; i++) {
        result[i] = NULL;
    }

    int count = 0;

    if (number & (1 << 0))
        result[count++] = "wink";

    if (number & (1 << 1))
        result[count++] = "double blink";

    if (number & (1 << 2))
        result[count++] = "close your eyes";

    if (number & (1 << 3))
        result[count++] = "jump";

    // reverse if bit 4 is set
    if (number & (1 << 4)) {
        for (int i = 0; i < count / 2; i++) {
            const char *tmp = result[i];
            result[i] = result[count - 1 - i];
            result[count - 1 - i] = tmp;
        }
    }

    result[count] = NULL; // NULL-terminate

    return result;
}