//-----------------
// E/S :

const int I1 = 2 , I2 = 3, V1 = 12;
const int RedD = LED_BUILTIN ;

// Variables :

unsigned int ValuePot = 0;
int StateI1 = 0, StateI2 = 0, RedDState = 0, ValueV1 = 0;

//Timers / FrÃ©quences :
unsigned int Period0 = 20;
unsigned long fRedD = 1000000, Period = 0;
unsigned long previousTimeD = 0, previousTime1 = 0, previousTime2 =0, previousTime0 = 0;
float Tempo = 0;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(RedD, OUTPUT);
  pinMode(V1, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:

  //Etat Des interupteurs + Valeur potentiomÃ¨tre + Timer:
  
  unsigned long Time = micros();
  StateI1 = digitalRead(I1);
  StateI2 = digitalRead(I2);
  ValuePot = analogRead(A0);

  //Conversion de la valeur du potentiomÃ¨tre :

  ValuePot = map(ValuePot, 0 , 1023, 10000, 2000);
  float PeriodVP = ValuePot;

  if ( StateI1 == LOW)
  {
    //Diode allumÃ©e en permanence + Signal V1 :
    
    digitalWrite(RedD, HIGH);
    if ( Time - previousTime0 >= Period0)
    {
      ValueV1 = 1 - digitalRead(V1);
      digitalWrite(V1, ValueV1);
      previousTime0 = Time;  
    }   
  }
  if ( StateI1 == HIGH)
  {
    //Diode Rouge qui clignote Ã  1Hz :

    if (Time - previousTimeD >= fRedD)
    {
      previousTimeD = Time;
      RedDState = 1 - digitalRead(RedD);
      digitalWrite(RedD, RedDState);
    }
    if ( StateI2 == LOW) //Rapport Cyclique 1/4 :
    {
      Tempo = PeriodVP/4.0;
      unsigned long Tampon1 = Tempo;
      Period = Tempo;
      
      if ( Time + Period - previousTime1 >= PeriodVP and digitalRead(V1) == LOW or Time - previousTime1 >= Period and digitalRead(V1) == HIGH)
      {
        ValueV1 = 1 - digitalRead(V1);
        digitalWrite(V1, ValueV1);
        previousTime1 = Time;  
      }     
    }
    if ( StateI2 == HIGH) //Rapport Cyclique de 3/4 :
    {
      Tempo = (3.0*PeriodVP)/4.0;
      unsigned long Tampon2 = Tempo;
      Period = Tempo;
      
      if ( Time + Period - previousTime1 >= PeriodVP and digitalRead(V1) == LOW or Time - previousTime1 >= Period and digitalRead(V1) == HIGH)
      {
        ValueV1 = 1 - digitalRead(V1);
        digitalWrite(V1, ValueV1);
        previousTime1 = Time;  
      }      
    }
  }
  
}
