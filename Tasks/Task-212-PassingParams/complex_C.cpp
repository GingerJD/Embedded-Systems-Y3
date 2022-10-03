#include "complex_C.hpp"
#include "mbed.h"
#include "uop_msb.h"

using namespace uop_msb;
LCD_16X2_DISPLAY display;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    display.printf("%s = %.3f + j%.3f\n", strName, u.real, u.imag);
}

void floatDisplay(const char *strName, const float a){
    display.printf("%s = %.4f\n",strName, a);
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b){
   ComplexNumber_C y = complexAdd( a,(complexNegate(b)));
    return y;
}

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C y;
    y.real = a.real * b.real;
    y.imag = a.imag * b.imag;
    return y;
}

ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C y;
    y.real = a.real / b.real;
    y.imag = a.imag / b.imag;
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C a){
    ComplexNumber_C y;
    y.real = -1*a.real;
    y.imag = -1*a.imag;
    return y;
}

float complexMagnitude(const ComplexNumber_C a){
    float y = sqrt((a.real*a.real)+(a.imag*a.imag));
    return y;
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a){
    ComplexNumber_C y;
    y.real = a.real;
    y.imag = -1*a.imag;
    return y;
}