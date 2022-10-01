#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASKC 0b0000000001001100
#define LEDMASKB 0b0100000010000001
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut ledsC(PortC, LEDMASKC);
PortOut ledsB(PortB, LEDMASKB);

int main()
{
    while (true) {
        ledsC = ledsC^LEDMASKC;   
        ledsB = ledsB^LEDMASKB;
        wait_us(500000);
 
    }
}




