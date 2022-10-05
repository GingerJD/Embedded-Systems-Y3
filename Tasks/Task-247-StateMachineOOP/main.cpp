#include "uop_msb.h"
#include "SwitchTimerLedManager.hpp"
#include "LedLogic.hpp"
#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;

Timer tmrLED;
SwitchTimerLedManager fsm1(BTN1_PIN, SwitchTimerLedManager::UP);
SwitchTimerLedManager fsm2(BTN2_PIN, SwitchTimerLedManager::DOWN);

LedLogic ledGreen(TRAF_GRN1_PIN, 250ms);
LedLogic ledYellow(TRAF_YEL1_PIN , 450ms);
LedLogic ledRed(TRAF_RED1_PIN, 750ms);

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

microseconds timeLED;

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);
    disp = 0;
    
    //Start LED timer
    tmrLED.start();
    disp = count;

    while (true) {

        // **********
        //Poll inputs
        // **********
        timeLED = tmrLED.elapsed_time();
        fsm1.readInputs();
        fsm2.readInputs();
        ledGreen.readInput();
        ledYellow.readInput();
        ledRed.readInput();

        // **********************************
        // UPDATE "STATE" for buttons A and B
        // **********************************
        fsm1.updateState(count);
        fsm2.updateState(count);
        ledGreen.updateState();
        ledYellow.updateState();
        ledRed.updateState();

        // ********************************
        // UPDATE "STATE" for LED and Timer
        // ********************************
        //if (timeLED >= 250ms) {
            //greenLED = !greenLED;
            //tmrLED.reset();
        //}

        // UPDATE OUTPUTS
        disp = count;
  
    }
}





