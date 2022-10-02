#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;
TimerCompat sw2debounce;
TimerCompat sw3debounce;
// THE CODE BELOW IS NOT A SOLUTION
//
// IT IS FUNDAMENTALLY FLAWED (AND INCOMPLETE)
//
//
// Switch states
typedef enum {
  WAIT_FOR_PRESS,
  WAITING_1,
  WAIT_FOR_REL,
  WAITING_2
} SWITCH_STATE;

//set initial states
SWITCH_STATE sw_state2 = WAIT_FOR_PRESS;
SWITCH_STATE sw_state3 = WAIT_FOR_PRESS;

int main()
{
    
    //Start flashing timer
    tmr_flash.start();
    

    while (true) {
        long long flash_time = tmr_flash.read_ms();
        long long sw2_time = sw2debounce.read_ms();
        long long sw3_time = sw3debounce.read_ms();

        if (flash_time >= 500) {
            ledYel = !ledYel;
            tmr_flash.reset();
        }
        
        //Switch 3
        switch (sw_state3){
            case WAIT_FOR_PRESS:
            if (SW3.read() == 1){
                sw_state3 = WAITING_1;
                ledRed = !ledRed;
                sw3debounce.start();
            }
            break;

            case WAITING_1:
            if(sw3_time >= 300){
                sw_state3 = WAIT_FOR_REL;
                sw3debounce.stop();
                sw3debounce.reset();
            }
            break;

            case WAIT_FOR_REL:
            if(SW3.read() == 0){
                sw_state3 = WAITING_2;
                sw3debounce.start();
            }
            break;

            case WAITING_2:
            if(sw3_time >=300){
                sw_state3 = WAIT_FOR_PRESS;
                sw3debounce.stop();
                sw3debounce.reset();
            }
            break;

            default:
            sw_state3 = WAIT_FOR_PRESS;
        }
        
        //Switch 2
        switch (sw_state2){
            case WAIT_FOR_PRESS:
            if (SW2.read() == 1){
                sw_state2 = WAITING_1;
                ledGrn = !ledGrn;
                sw2debounce.start();
            }
            break;

            case WAITING_1:
            if(sw2_time >= 300){
                sw_state2 = WAIT_FOR_REL;
                sw2debounce.stop();
                sw2debounce.reset();
            }
            break;

            case WAIT_FOR_REL:
            if(SW2.read() == 0){
                sw_state2 = WAITING_2;
                sw2debounce.start();
            }
            break;

            case WAITING_2:
            if(sw2_time >=300){
                sw_state2 = WAIT_FOR_PRESS;
                sw2debounce.stop();
                sw2debounce.reset();
            }
            break;

            default:
            sw_state2 = WAIT_FOR_PRESS;
        }

        
        
        
        
        
        //Wait for switch press and release (by BLOCKING)
        //while (SW2.read() == 0);
        //ledRed = !ledRed;
        //wait_us(300000);

        //while (SW2.read() == 1);
        //wait_us(300000);        

        //Toggle Yellow LED
        //if(flash_time >=500){
       //     ledYel = !ledYel;
       //     tmr_flash.reset();
       // }
        //ledYel = !ledYel;
        //while (tmr_flash.read_ms() < 500);
        //tmr_flash.reset();
    }
}





