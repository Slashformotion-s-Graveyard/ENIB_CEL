#ifndef TOOLS_BPWITCH_H
#define TOOLS_BPWITCH_H

#include "Arduino.h"//or "arduino.h"

namespace Tools{
    namespace BpSwitch{

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
