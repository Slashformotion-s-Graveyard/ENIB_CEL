#include "genLowFreq.hpp"

namespace Tools
{
    namespace FreqGen
    {
        FrequencyGenerator::FrequencyGenerator(uint8_t pin, byte frequency, float dutyCycle, bool enable) : m_pin{pin}, m_enable{enable}, m_dutyCycle{dutyCycle}, m_frequency{frequency}
        {
            float period{1 / float(m_frequency) * 1000000}; //period in microseconds

            m_highTime = static_cast<unsigned long>(period * m_dutyCycle / 100.0);
            m_lowTime = static_cast<unsigned long>(period * (100.0 - m_dutyCycle) / 100.0);

            pinMode(m_pin, OUTPUT);
            m_refTime = micros();
            m_state = false;
        }

        bool FrequencyGenerator::compute()
        {
            if (!m_enable)
            {
                m_state = false;
                return false;
            }

            auto curTime = micros();
            auto difTime = (m_state) ? m_highTime : m_lowTime;
            if (curTime >= difTime + m_refTime)
            {
                m_state = !m_state;
                digitalWrite(m_pin, uint8_t(m_state));
                m_refTime = curTime;

                return true;
            }

            return false;
        }

        void FrequencyGenerator::setEnable(bool enable)
        {
            if (enable) //if enable frequency generator
            {
                m_refTime = micros();
            }
            else //disable frequency generator
            {
                digitalWrite(m_pin, LOW);
            }

            m_enable = enable;
        }

        void FrequencyGenerator::setFrequency(byte frequency, float dutyCycle)
        {
            m_frequency = frequency;
            m_dutyCycle = dutyCycle;

            float period{1 / float(m_frequency) * 1000000}; //period in microseconds

            m_highTime = static_cast<unsigned long>(period * m_dutyCycle / 100.0);
            m_lowTime = static_cast<unsigned long>(period * (100.0 - m_dutyCycle) / 100.0);

            m_refTime = micros();
            m_state = false;

            digitalWrite(m_pin, LOW);
        }

    } // namespace FreqGen
} // namespace Tools
