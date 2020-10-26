#ifndef TOOLS_BPWITCH_H
#define TOOLS_BPWITCH_H
#include "Arduino.h"

namespace Tools
{
    namespace BpSwitch
    {

        class Switch
        {
        public:
            Switch(byte pin); //Constructor
            ~Switch();           // destructor
            void actualizeState();

            void onSwitch();

            bool getState();

        private:
            byte m_pin; // pin
            bool m_state;  // state of the switch
        };
    } // namespace BpSwitch
} //namespace Tools

#endif
