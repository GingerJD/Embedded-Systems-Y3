#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define led1 PB_0
#define led2 PB_7
#define led3 PB_14

// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
BusOut leds2(led1, led2, led3);
int main()
{
    while (true) {
        
        for(int i = 0; i<=7; i++){
            leds = i;
            leds2 = i;
            
            wait_us(500000);
        }

        //leds = 1;   //Binary 000
        //wait_us(500000);
        //leds = 7;   //Binary 111
       // wait_us(500000); 
   
    }
}


