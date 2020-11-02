#include "bpSwitch.h"
#include "stdint.h"
#include "Arduino.h"

namespace Tools
{
    namespace BpSwitch
    {
        Switch::Switch(byte pin) // constructeur
            : m_pin(pin)
        {
            pinMode(pin, INPUT);
            this->m_state = static_cast<bool>(digitalRead(pin));
        }

        Switch::~Switch() {} // destructeur

        void Switch::actualizeState()
        {
            m_state = static_cast<bool>(digitalRead(this->m_pin));
        }

        bool Switch::getState()
        {
            return this->m_state;
        }
        void Switch::onSwitch(){
            
        }

    } // namespace BpSwitch
} // namespace Tools
