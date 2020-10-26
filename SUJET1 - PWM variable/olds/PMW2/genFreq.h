#ifndef TOOLS_GEN_LOW_FREQ_H
#define TOOLS_GEN_LOW_FREQ_H

#include "Arduino.h"

//using namespace std;

namespace Tools
{
    namespace FreqGen
    {
        class FrequencyGenerator //class to manage a low frequency generator
        {
        public:
            FrequencyGenerator(byte pin, long frequency, float dutyCycle, bool enable); //advanced constructor
            //virtual  ~FrequencyGenerator();

            void setEnable(bool enable);                                  //enable/disable frequency generator. Output is set at 0 if disabled
            void setFrequency(long frequency, float dutyCycle = 50.0); //change frequency

            byte getState() //return current pin state : HIGH/LOW
            {
                return byte(m_state); //return current pin state with arduino
            }

            bool getEnable() //get current generator enable state
            {
                return m_enable;
            }

            bool compute(); //return true if a switch happened

        private:
            byte m_pin; //pin used to generate frequency
            bool m_enable; //is the generator enable or disabled

            float m_dutyCycle;   //rapport cyclique en %
            int m_frequency; //generated frequency

            unsigned long m_highTime, m_lowTime; //private invariant : HIGH state time in the generated frequency and LOW state time
            unsigned long m_refTime;             //beginning period time
            bool m_state;                        //current pin state
        };

    } // namespace FreqGen
} // namespace Tools

#endif
