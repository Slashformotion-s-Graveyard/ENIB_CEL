#include "digitalWriteFast.h"
#define I1 (2)
#define I2 (3)
#define L (10)
#define S (11)
#define PIN_A_POTAR (A0)

bool v1, v2;
bool s, last_s, led, last_led;
unsigned long clock, chrono, period, t_monte, chrono2;
float rapport_cyclique;
bool front_montant_v1 = true, front_montant_v2 = false;

// EVERY TIME RELATED VARIABLE OR CONSTANT IS EXPRESSED IN MICROSECONDS

void setup()
{
    pinModeFast(S, OUTPUT);
    pinModeFast(L, OUTPUT);
    pinModeFast(I1, INPUT);
    pinModeFast(I2, INPUT);
    pinModeFast(PIN_A_POTAR, INPUT); //
    Serial.begin(115200);
    chrono = 0;
    chrono2 = 0;
}

void loop()
{
    clock = micros(); // on met a jour / implemente l'horloge

    if (digitalReadFast(I1) == 0)
    {
        chrono = clock;
        digitalWriteFast(L, HIGH);
        digitalWriteFast(S, HIGH);
        while (clock < chrono + 50)
        {
            clock = micros();
        }
        digitalWriteFast(S, LOW);
        while (clock < chrono + 100)
        {
            clock = micros();
        }

        chrono = 0;
    }

    if (digitalReadFast(I1) == 1)
    {
        //----------LED----------------------

        if (chrono == 0)
        {
            chrono = clock;
        }

        if (clock > chrono + 500000)
        {
            digitalWriteFast(L, LOW);
        }

        if (clock > chrono + 1000000 || clock)
        {
            digitalWriteFast(L, HIGH);
        }
        //---------rapport cyclique------------

        rapport_cyclique = (digitalReadFast(I2) == 0 ? 0.25 : 0.75);

        //----------potar----------------
        period = int((analogRead(PIN_A_POTAR) / 1023) * 8000 + 2000);
        t_monte = period * rapport_cyclique;

        if (chrono2 == 0)
        {
            chrono2 = clock;
        }

        if (clock > chrono2 + t_monte)
        {
            digitalWriteFast(S, LOW);
        }
        if (clock > chrono2 + period || clock < chrono2 + t_monte)
        {
            digitalWriteFast(S, HIGH);
            if (clock > chrono2 + period)
            {
                chrono2 = 0;
            }
        }
    }
}