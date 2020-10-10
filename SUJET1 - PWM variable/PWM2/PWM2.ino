
   #define PIN_D_I1  2 
#define PIN_D_I2  3
#define PIN_D_LED  9 
#define PIN_D_OUT  211
#define PIN_A_POTAR  A0 
#include "bpSwitch.hpp"
#include "genFreq.hpp"

Tools::Switch::BpSwitch s1,s2; 
Tools::FreqGen::FrequencyGenerator led, sortie;


int freq;

int get_potar() {
  return analogRead(PIN_A_POTAR);
}

int map_to_freqs(const int value, const int xmin, const int xmax,const int ymin, const int ymax){
  auto X = (x-xmin)/(xmax-xmin)
  return X*(ymax-ymin)+ymin
}

int get_freq_potar(){
  return map_to_freqs(get_potar(), 0, 1023, 100, 500)
}

void setup()
{
  Tools::Switch::initButtonSwitch(s1, PIN_D_I1);
  Tools::Switch::initButtonSwitch(s2, PIN_D_I2);
  led.setEnable(true);
  sortie.setEnable(true);
  
}

void loop(){
  Tools::Switch::actButtonState(s1);
  Tools::Switch::actButtonState(s2);
  if (s1.boolean) {
    led.setFrequency(1,100);
    sortie.setFrequency(20000, 50)
  } else {
    led.setFrequency(1,50)
      freq = static_cast<unsigned int>(get_freq_potar())
    if(s2.boolean) {
      sortie.setFrequency(freq, 25)
    }else {
      sortie.setFrequency(freq, 75)
    }

  }





  led.compute()
  sortie.compute()

}





