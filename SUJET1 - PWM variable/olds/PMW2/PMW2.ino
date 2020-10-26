#define PIN_D_I1 2
#define PIN_D_I2 3
#define PIN_D_LED 10
#define PIN_D_OUT 11
#define PIN_A_POTAR A0
#include "bpSwitch.h"
#include "genFreq.h"

Tools::BpSwitch::Switch s1(PIN_D_I1), s2(PIN_D_I2);
Tools::FreqGen::FrequencyGenerator sortie(PIN_D_OUT, 20000, 50.0, true);
Tools::FreqGen::FrequencyGenerator led(PIN_D_LED, 1, 50.0, true);

int freq;

int get_potar()
{
  return analogRead(PIN_A_POTAR);
}

int map_to_freqs(const int value, const int xmin, const int xmax, const int ymin, const int ymax)
{
  int X = (value - xmin) / (xmax - xmin);
  return X * (ymax - ymin) + ymin;
}

int get_freq_potar()
{
  return map_to_freqs(get_potar(), 0, 1023, 100, 500);
}

void setup()
{
  // Serial.begin(115200);
}

void loop()
{
//  s1.actualizeState();
  
//  Serial.print(s1.getState());
//  Serial.print(s2.getState());
//  Serial.print("  ");
//  Serial.print(sortie.getState());
//  Serial.println(led.getState());
  
//  if (!s1.getState())
//  {
//    led.setFrequency(1, 99.0);
//    sortie.setFrequency(20000, 50);
//  }
//  else
//  {
//    led.setFrequency(1, 50.0);
//    s2.actualizeState();
//    freq = (map(analogRead(A0),0,1023,100,500));
//    Serial.println(freq);
//
//    if (!s2.getState())
//    {
//      sortie.setFrequency(freq, 25.0);
//    }
//    else
//    {
//      sortie.setFrequency(freq, 75.0);
//    }
//  }
//
//  led.compute();
  sortie.compute();
}
