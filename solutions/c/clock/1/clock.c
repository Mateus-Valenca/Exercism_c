#include "clock.h"
clock_t clock_create(int hour, int minute)
{
    clock_t new_clock;

    // normaliza minutos
    hour += minute / 60;
    minute = minute % 60;

    // ajusta negativos em minutos
    if (minute < 0) {
        minute += 60;
        hour--;
    }

    // normaliza horas
    hour = (hour % 24 + 24) % 24;

    snprintf(new_clock.text, MAX_STR_LEN, "%02d:%02d", hour, minute);

    return new_clock;
}
clock_t clock_add(clock_t clock, int minute_add)
{
    int hour, minute;

    // string → int
    sscanf(clock.text, "%d:%d", &hour, &minute);

    // lógica
    minute += minute_add;
    hour += minute / 60;
    minute %= 60;

    if (minute < 0) {
        minute += 60;
        hour--;
    }

    if (hour < 0)
        hour = (hour % 24 + 24) % 24;
    else
        hour %= 24;

    // int → string
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hour, minute);

    return clock;    
}
clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour, minute;

    // string → int
    sscanf(clock.text, "%d:%d", &hour, &minute);

    // lógica
    minute -= minute_subtract;
    hour += minute / 60;
    minute %= 60;

    if (minute < 0) {
        minute += 60;
        hour--;
    }

    if (hour < 0)
        hour = (hour % 24 + 24) % 24;
    else
        hour %= 24;

    // int → string
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hour, minute);

    return clock;        
}
bool clock_is_equal(clock_t a, clock_t b)
{
    int hour_a, minute_a, hour_b,minute_b;

    // string → int
    sscanf(a.text, "%d:%d", &hour_a, &minute_a);    

     // string → int
    sscanf(b.text, "%d:%d", &hour_b, &minute_b);  
    return (hour_a == hour_b) && (minute_a == minute_b);
}