int Ab = A5, Ac = A3, bpin = 3, bstate = LOW, dbstate = LOW, lrpin = 2, lvpin = 7;
double Vb = 0.0, Vc=0.0, Ib = 0.0, Ic = 0.0, beta = 0.0;
double t = 0.0, dt = 50.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Ab, INPUT);
  pinMode(Ac, INPUT);
  pinMode(bpin, INPUT);
  pinMode(lrpin, OUTPUT);
  pinMode(lvpin, OUTPUT);

  
  Serial.begin(9600);
}

inline double
a2t(int A)
{
  double V = (double(A)*5)/1024.0;
  return V;
}

inline double 
getCurrent(double V, double R)
{
  double I = (5-V)/R;
  return I;  
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();

  if(t-dt > 50)
  {
    dt = t;
    bstate = digitalRead(bpin);

    if (bstate != dbstate)
    {
      dbstate = bstate;

      if (bstate == HIGH)
      {
        Vb = a2t(analogRead(Ab));
        Vc = a2t(analogRead(Ac));
        Ib = getCurrent(Vb, 2000000.0);
        Ic = getCurrent(Vc, 2500.0);
    
        beta = Ic/Ib;

        if (beta > 440 && beta < 600) //Les caractéristiques nous informent que le béta du transistor doit être entre 450 et 900. 
        {                             //Les paramétres içi présents prennent en compte la marge d'erreur de l'Arduino.
          digitalWrite(lvpin, HIGH);
          digitalWrite(lrpin, LOW);
          Serial.println("Transistor ok.");
          Serial.print("beta =");
          Serial.print(int(beta));
          Serial.print("; Vbe =");
          Serial.print(Vb);
          Serial.print("V; Vce =");
          Serial.print(Vc);
          Serial.print("V; Ic =");
          Serial.print(Ic*1000);
          Serial.print("mA\n");
        }
        else
        {
          digitalWrite(lvpin, LOW);
          digitalWrite(lrpin, HIGH);
          Serial.println("Transistor defaillant.");
        }

      
      }
    }
  }
}