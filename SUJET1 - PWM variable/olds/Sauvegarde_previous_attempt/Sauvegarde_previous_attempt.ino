
bool v1, v2;
int x;
int period;
bool led_a = true, v1_done_led = false;
unsigned int time_d = 0, last_micros, new_micros;
#define I1 2
#define I2 3
#define L 10
#define S 11
#define PIN_A_POTAR A0

#include "digitalWriteFast.h"

void setup()
{
  // put your setup code here, to run once:

  pinModeFast(I1, INPUT);
  pinModeFast(I2, INPUT);
  pinModeFast(L, OUTPUT);
  pinModeFast(S, OUTPUT);
  //  Serial.begin(9600);
}

void loop()
{

  // acquisition des données
  v1 = digitalReadFast(I1);

  if (v1_done_led == false)
  {
    digitalWriteFast(L, HIGH);
    v1_done_led = true;
  }
  // logique
  if (v1)
  {

    digitalWriteFast(S, HIGH); // on allume la sortie

    delayMicroseconds(25);

    digitalWriteFast(S, LOW); // on éteint la sortie

    delayMicroseconds(22);
  }
  else
  {

    v1_done_led = true;
    if (time_d > 500000)
    {
      //       Serial.print(time_d); Serial.println(led_a);
      led_a = !led_a;
      time_d = 0;
      if (led_a)
      {
        digitalWriteFast(L, HIGH);
      }
      else
      {
        digitalWriteFast(L, LOW);
      }
    }

    new_micros = micros();

    time_d = time_d + new_micros - last_micros;
    last_micros = new_micros;

    // acquisition de la valeur variable du potentiomêtre
    period = map(analogRead(A0), 0, 1023, 2000, 10000); // frequ cible

    v2 = digitalReadFast(I2);
    if (v2)
    {
      digitalWriteFast(S, HIGH);

      delayMicroseconds(period * 0.25);

      digitalWriteFast(S, LOW);

      delayMicroseconds(period * 0.70);
    }
    else
    {
      digitalWriteFast(S, HIGH);

      delayMicroseconds(period * 0.73);

      digitalWriteFast(S, LOW);

      delayMicroseconds(period * 0.15);
    }
  }
}
