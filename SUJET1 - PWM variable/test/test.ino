#include "digitalWriteFast.h"
#define I1 (2)
#define I2 (3)
#define L (10)
#define S (11)
#define PIN_A_POTAR (A0)

bool v1, v2;
bool s, last_s, led, last_led;
unsigned long curTime, s_00_01_timer, lastTime, s_10_timer, s_11_timer, led_timer;
int period;
bool front_montant_v1 = true, front_montant_v2 = false;

// EVERY TIME RELATED VARIABLE OR CONSTANT IS EXPRESSED IN MICROSECONDS

void setup()
{
    pinModeFast(S, OUTPUT);
    pinModeFast(L, OUTPUT);
    pinModeFast(I1, INPUT);
    pinModeFast(I2, INPUT);
}

void loop()
{
    lastTime = curTime;
    curTime = micros();
    v1 = digitalReadFast(I1);
    last_s = s;
    last_led = led;

    if (!v1)
    {
        front_montant_v2 = true;
        if (front_montant_v1)
        {
            led = true;
            s_00_01_timer = 0;
        }
        s_00_01_timer = s_00_01_timer + curTime - lastTime;

        if (s_00_01_timer >= 25) // every 25µs we switch the state of the output
        {
            s_00_01_timer = 0;
            s = !s; // on inverse l'état de la sortie
        }

        front_montant_v1 = false;
    }
    else
    {
        front_montant_v1 = true;
        v2 = digitalReadFast(I2);
        period = int((analogRead(PIN_A_POTAR) / 1023) * 8000 + 2000);

        if (front_montant_v2)
        {
            s_10_timer = 0;
            s_11_timer = 0;
            led_timer = 0;
        }
        
        if (led_timer >= 500000) {
            led = !led;
            
        }

        if (!v2)
        {
            if (s && s_10_timer >= int(period * 0.25))
            {
                s = false;
            }
            else if (!s && s_10_timer >= int(period * 0.75))
            {
                s = true
            }
            s_10_timer = s_10_timer + curTime - lastTime;
        }
        else
        {
            if (s && s_11_timer >= int(period * 0.75))
            {
                s = false;
            }
            else if (!s && s_11_timer >= int(period * 0.25))
            {
                s = true
            }
            s_11_timer = s_11_timer + curTime - lastTime;
        }
        front_montant_v2 = false;
    }

    // SORTIE: action
    if (s != last_s)
    {
        if (s)
        {
            digitalWriteFast(S, HIGH);
        }
        else
        {
            digitalWriteFast(S, LOW);
        }
    }

    // LED: action
    if (led != last_led)
    {
        if (led)
        {
            digitalWriteFast(L, HIGH);
        }
        else
        {
            digitalWriteFast(L, LOW);
        }
    }
}