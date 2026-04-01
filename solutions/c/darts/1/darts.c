#include "darts.h"

float euclidean_distance(coordinate_t pos)
{
    return sqrt(pos.x * pos.x + pos.y * pos.y);
}
uint8_t score(coordinate_t pos)
{
    uint8_t points;
    float r = euclidean_distance(pos);
    if (r > 10)
    {
    points = 0;
    } 
    else if (r > 5) 
    {
    points = 1;
    } 
    else if (r > 1) 
    {
    points = 5;
    } else 
    {
    points = 10;
    }    
    return points; 
}