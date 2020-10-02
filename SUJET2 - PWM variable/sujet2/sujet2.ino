

const int I1 = 2, I2 = 3, L = 10, S = 11; // interrupteurs 1 et 22, led, sortie
bool v1, v2;
int x;
int period;
void setup()
{
  // put your setup code here, to run once:
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(L, OUTPUT);
  pinMode(S, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  // acquisition des données
  v1 = bool(digitalRead(I1));
  v2 = bool(digitalRead(I2));
  

  // logique
  if (v1)
  {
    digitalWrite(L, HIGH); // on allume la LED
    digitalWrite(S, HIGH); // on allume la sortie

    
    delayMicroseconds(25);

    digitalWrite(S, LOW); // on éteint la sortie

    delayMicroseconds(25);
    
  }
  else
  {
    // on s'occupe d'abord de la led
    if ((millis() % 1000) < 500)
    {
      digitalWrite(L, HIGH);
    }
    else
    {
      digitalWrite(L, LOW); 
    }

    // acquisition de la valeur variable du potentiomêtre
    period = map(analogRead(A0), 0, 1023, 2, 10) * 1000;

    Serial.print("   ");
    Serial.println(x);
    if (v2)
    {
      digitalWrite(S, HIGH);

      delayMicroseconds(period * 0.25);

      digitalWrite(S, LOW);

      delayMicroseconds(period * 0.75);
    }
    else
    {
      digitalWrite(S, HIGH);

      delayMicroseconds(period * 0.75);

      digitalWrite(S, LOW);

      delayMicroseconds(period * 0.25);
    }
  }
}
