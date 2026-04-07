#include "kindergarten_garden.h"
const char *students[] = {
    "Alice","Bob","Charlie","David","Eve","Fred",
    "Ginny","Harriet","Ileana","Joseph","Kincaid","Larry"
};
plant_t char_to_plant(char c)
{
    switch (c)
    {
        case 'C': return CLOVER;
        case 'G': return GRASS;
        case 'R': return RADISHES;
        case 'V': return VIOLETS;
    }
    return CLOVER;
}
plants_t plants (const char *diagram, const char *student)
{
    const char *newline = strchr(diagram, '\n');

    const char *row1 = diagram;// starts at beginning
    const char *row2 = newline + 1;// starts after '\n'
int index = -1;

for (int i = 0; i < 12; i++)
{
    if (strcmp(students[i], student) == 0)
    {
        index = i;
        break;
    }
}
int offset = index * 2;    
    plants_t result;

result.plants[0] = char_to_plant(row1[offset]);
result.plants[1] = char_to_plant(row1[offset + 1]);
result.plants[2] = char_to_plant(row2[offset]);
result.plants[3] = char_to_plant(row2[offset + 1]);
    return result;
}