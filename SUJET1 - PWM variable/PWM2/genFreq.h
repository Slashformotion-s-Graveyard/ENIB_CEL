#ifndef TOOLS_GEN_LOW_FREQ_H
#define TOOLS_GEN_LOW_FREQ_H

#include "Arduino.h" //or "arduino.h"

namespace Tools
{
    namespace FreqGen
    {
        class FrequencyGenerator //class to manage a frequency generator
        {
        public:
            FrequencyGenerator(uint8_t pin, byte frequency, float dutyCycle = 50.0, bool enable = true); //advanced constructor

            void setEnable(bool enable);                               //enable/disable frequency generator. Output is set at 0 if disabled
            void setFrequency(byte frequency, float dutyCycle = 50.0); //change frequency

            uint8_t getState() //return current pin state : HIGH/LOW
            {
                return uint8_t(m_state); //return current pin state with arduino
            }

            bool getEnable() //get current generator enable state
            {
                return m_enable;
            }

            bool compute(); //return true if a switch happened

        private:
            uint8_t m_pin; //pin used to generate frequency
            bool m_enable; //is the generator enable or disabled

            float m_dutyCycle; //rapport cyclique en %
            byte m_frequency;  //generated frequency

            unsigned long m_highTime, m_lowTime; //private invariant : HIGH state time in the generated frequency and LOW state time
            unsigned long m_refTime;             //beginning period time
            bool m_state;                        //current pin state
        };

    } // namespace FreqGen
} // namespace Tools

#endif
