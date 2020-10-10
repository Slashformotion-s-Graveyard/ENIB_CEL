#include "Arduino.h" //or "arduino.h"
#include "bpSwitch.h"

namespace Tools
{
    namespace BpSwitch
    {
        

        void initSwitch(Switch &s, uint8_t pin){
            s.pin = pin;
            pinMode(pin, INPUT);
            s.boolean = static_cast<bool>(digitalRead(pin))
        }

        void actSwitchState(Switch &s)
        {
            s.boolean = static_cast<bool>(digitalRead(pin))
        }
    } // namespace Switch
} // namespace Tools
