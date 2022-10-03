#include "mbed.h"
#include "complex_C.hpp"





// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    //complexDisplay("p", p);
    //complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    ComplexNumber_C sub = complexSubtract(p, q);
    ComplexNumber_C mult = complexMultiply(p, q);
    ComplexNumber_C div = complexDivide(p, q);
    ComplexNumber_C neg = complexNegate(p);
    float mag = complexMagnitude(p);
    ComplexNumber_C con = complexConjugate(p);

    while(true){
        complexDisplay("p+q", sum);
        wait_us(5000000);
        complexDisplay("p-q", sub);
        wait_us(5000000);
        complexDisplay("p*q", mult);
        wait_us(5000000);
        complexDisplay("p/q", div);
        wait_us(5000000);
        complexDisplay("-p", neg);
        wait_us(5000000);
        floatDisplay("mag p = %f",mag);
        wait_us(5000000);
        complexDisplay("p con", con);
        wait_us(5000000);
    }
    while(true){ 

    }
}
