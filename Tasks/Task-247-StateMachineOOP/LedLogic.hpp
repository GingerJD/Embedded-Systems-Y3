#include "mbed.h"
#include <chrono>
using namespace std::chrono;

class LedLogic {
    private:
    typedef enum {ON, OFF} STATE;
    Timer _tmr;
    DigitalOut _led;
    microseconds _duration = 0ms;
    microseconds _currentTime = 0ms;

    public:
    LedLogic(PinName pin, microseconds duration) : _led(pin), _duration(duration) {
        _tmr.start();
        _led = 0;
    }
      
    void start() {
        _tmr.start();
    }

    void stop(){
        _tmr.stop();
    }

    void readInput(){
        _currentTime = _tmr.elapsed_time();
    }

    void updateState(){
        if (_currentTime >= _duration){
            _led = !_led;
            _tmr.reset();
            _currentTime = 0ms;
        }
    }

};