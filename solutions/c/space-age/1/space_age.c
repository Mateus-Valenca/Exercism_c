#include "space_age.h"
const double orbital_period_ratio[8] = { 0.2408467,0.61519726, 1.0, 1.8808158,
    11.862615, 29.447498, 84.016846, 164.79132};
    const double c_earth_year_seconds = 31557600.0;
float age(planet_t planet, int64_t seconds)
{
    if (planet < MERCURY || planet > NEPTUNE) return -1.0f;
    return seconds/(c_earth_year_seconds * orbital_period_ratio[planet]);
}