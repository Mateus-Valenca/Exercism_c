#include "resistor_color.h"

int color_code(resistor_band_t resistor_band)
{
    return resistor_band;
}

const resistor_band_t *colors(void)
{
    static const resistor_band_t all_colors[] ={
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return all_colors;
}