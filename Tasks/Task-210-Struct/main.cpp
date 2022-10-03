#include "mbed.h"
#include "uop_msb.h"
using namespace uop_msb;
// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;
LCD_16X2_DISPLAY display;

int main() {

    //Create instance of a complex number
    ComplexNumber_C p;
    ComplexNumber_C y;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};

    // TASK:
    y.real = p.real + q.real;
    y.imag = p.imag + q.imag;
    display.printf("Y = %.1f+%.1fi",y.real,y.imag);
    // Use printf to display as a complex number (hint: you need two placeholders)
    
    while (true) {
        //display.printf("Y = %f+%fi",y.real,y.imag);
    }
}
