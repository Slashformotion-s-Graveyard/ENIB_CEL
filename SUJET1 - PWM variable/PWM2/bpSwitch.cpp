#include "Arduino.h" //or "arduino.h"
#include "bpSwitch.hpp"

namespace Tools
{
    namespace BpSwitch
    {
        void initButtonSwitch(BpSwitch &bp, uint8_t pin)
        {
            bp.pin = pin;
            pinMode(pin, INPUT_PULLUP);
            bp.isFirstButtonLoop = true;

            bp.switchState = LOW;
        }

        void actButtonState(BpSwitch &bp) //this function actualize the button state and have to be called every Arduino "loop"
        {
            auto curState = !bool(digitalRead(bp.pin));

            if (!curState) //if button is released
            {
                bp.isFirstButtonLoop = true; //say that we can now press again the button
                return;                      //exit function now
            }

            if (curState && bp.isFirstButtonLoop) //if the button is pressed and it's the first loop since it is
            {
                bp.isFirstButtonLoop = false; //say that the first loop since the button is pressed had already been executed

                bp.switchState = !bp.switchState;
            }
        }




        void initSwitch(Switch &s, uint8_t pin){
            s.pin(pin);
            pinMode(pin, INPUT);
            s.boolean = static_cast<bool>(digitalRead(pin))
        }

        void actSwitchState(Switch &s)
        {
            s.boolean = static_cast<bool>(digitalRead(pin))
        }
    } // namespace Switch
} // namespace Tools
