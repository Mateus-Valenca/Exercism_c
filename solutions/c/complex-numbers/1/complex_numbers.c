#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real+b.real);
    res.imag = (a.imag+b.imag);
    return res;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real-b.real);
    res.imag = (a.imag-b.imag);
    return res;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real*b.real - a.imag*b.imag);
    res.imag = (a.imag*b.real + a.real*b.imag);
    return res;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t res;
    res.real = (a.real*b.real + a.imag*b.imag)/(b.real*b.real + b.imag*b.imag);
    res.imag = (a.imag*b.real - a.real*b.imag)/((b.real*b.real + b.imag*b.imag));
    return res;
}

double c_abs(complex_t x)
{
   return sqrt(x.real*x.real + x.imag*x.imag);
}

complex_t c_conjugate(complex_t x)
{
    complex_t res;
    res.real = x.real;
    res.imag = -(x.imag);
    return res;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t res;
    double e_real = exp(x.real);
    res.real =  e_real*cos(x.imag);
    res.imag =  e_real*sin(x.imag);
    return res;
}
