#ifndef TOOLS_BPWITCH_H
#define TOOLS_BPWITCH_H

#include "Arduino.h"//or "arduino.h"

namespace Tools{
    namespace BpSwitch{

        struct BP
        {
            uint8_t pin;
            bool isFirstButtonLoop;//is it the first loop since the button is pressed

            uint8_t switchState;//state of the switch created by the button
        };

        void actButtonState(BpSwitch &bp); //this function actualize the button state and have to be called every Arduino "loop"
    
        void initButtonSwitch(BpSwitch &bp,uint8_t pin); //init button switch with the pin as INPUT_PULLUP and

        struct Switch
        {
            uint8_t pin;
            bool boolean;
        }

        void initSwitch(Switch &s, uint8_t pin);
        void actSwitchState(Switch &s);
    }
}

#endif
