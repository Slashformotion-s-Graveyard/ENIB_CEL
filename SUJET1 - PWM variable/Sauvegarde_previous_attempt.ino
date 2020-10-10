const int I1 = 2, I2 = 3, L = 9, S = 11; // interrupteurs 1 et 22, led, sortie
bool v1, v2;
int x;
int period;
bool led_a=true, v1_done_led=false;
unsigned int time_d=0, last_millis,new_millis ;
void setup()
{
  // put your setup code here, to run once:
  
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(L, OUTPUT);
  pinMode(S, OUTPUT);
//  Serial.begin(9600);
  
}

void loop(){

  // acquisition des données
  v1 = digitalRead(I1);
  
  if (v1_done_led == false)
  {
     digitalWrite(L, HIGH);
     v1_done_led = true;
  }
  // logique
  if (v1)
  {
    
    digitalWrite(S, HIGH); // on allume la sortie

    delayMicroseconds(20);

    digitalWrite(S, LOW); // on éteint la sortie

    delayMicroseconds(7);

  } else{  
     
    v1_done_led = true;
    if(time_d>500)
    {  
//       Serial.print(time_d); Serial.println(led_a);
       led_a = !led_a;
       time_d = 0;
       digitalWrite(L, int(led_a));
    }
    
   new_millis = millis();
   
   time_d = time_d + new_millis-last_millis;
   last_millis = new_millis;
    
    
    

    // acquisition de la valeur variable du potentiomêtre
    period = map(analogRead(A0), 0, 1023, 2000, 10000); // frequ cible

    v2 = digitalRead(I2);
    if (v2)
    {
      digitalWrite(S, HIGH);

      delayMicroseconds(period * 0.25);

      digitalWrite(S, LOW);

      delayMicroseconds(period * 0.70);
    }
    else
    {
      digitalWrite(S, HIGH);

      delayMicroseconds(period * 0.75);

      digitalWrite(S, LOW);

      delayMicroseconds(period * 0.13);
    }
  }
}




