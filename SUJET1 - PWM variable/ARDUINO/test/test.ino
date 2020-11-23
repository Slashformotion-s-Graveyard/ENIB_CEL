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
    Serial.begin(11520);
}

void loop()
{
    lastTime = curTime;
    curTime = micros();
    v1 = digitalReadFast(I1);
    Serial.print("Etat de I1 (sur la broche 2) = ");
    Serial.println(v1);
    Serial.print("Etat des timers: led_timer=");
    Serial.print(led_timer);
    Serial.print(" s_00_01_timer = ");
    Serial.print(s_00_01_timer);
    Serial.print(" s_10_timer = ");
    Serial.print(s_10_timer);
    ;
    Serial.print(" s_11_timer = ");
    Serial.println(s_11_timer);
    last_s = s;
    last_led = led;
    led_timer = led_timer + curTime - lastTime;

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
        Serial.print("Etat de I2 (sur la broche 3) = ");
        Serial.println(v2);
        period = int((analogRead(PIN_A_POTAR) / 1023) * 8000 + 2000);
        led_timer = led_timer + curTime - lastTime;

        if (front_montant_v2)
        {
            s_10_timer = 0;
            s_11_timer = 0;
            led_timer = 0;
        }

        if (led_timer >= 500000)
        {
            led = !led;
            led_timer=0;
        }

        if (!v2)
        {
            if (s && s_10_timer >= int(period * 0.25))
            {
                s = false;
                s_10_timer = 0;
            }
            else if (!s && s_10_timer >= int(period * 0.75))
            {
                s = true;
                s_10_timer = 0;
            }
            s_10_timer = s_10_timer + curTime - lastTime;
        }
        else
        {
            if (s && s_11_timer >= int(period * 0.75))
            {
                s = false;
                s_11_timer = 0;
            }
            else if (!s && s_11_timer >= int(period * 0.25))
            {
                s = true;
                s_11_timer = 0;
            }
            s_11_timer = s_11_timer + curTime - lastTime;
        }
        front_montant_v2 = false;
    }

    // SORTIE: action
    if (s != last_s)
    {
        Serial.print("En passant ici on switch la Sortie vers S = ");
        Serial.println(s);
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
        Serial.print("En passant ici on switch la led vers led = ");
        Serial.println(led);
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