
const int I1 = 2, I2 = 3, L = 10, S = 11; // interrupteurs 1 et 22, led, sortie
bool v1, v2;
int x;
int periode_ms;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(L, OUTPUT);
  pinMode(S, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  // acquisition des données
  v1 = bool(digitalRead(I1));
  v2 = bool(digitalRead(I2));
  Serial.print(v1); Serial.print("   "); Serial.println(v2);


  // logique
  if (v1== false) {
    digitalWrite(L, HIGH); // on allume la LED
    digitalWrite(S, HIGH); // on allume la sortie

    delayMicroseconds(50 / 2);

    digitalWrite(S, LOW); // on éteint la sortie

    delayMicroseconds(50 / 2);

  }
  else {
    // on s'occupe d'abord de la led
    if ((millis() % 1000) < 500) {
      digitalWrite(L, HIGH);
    }
    else {
      digitalWrite(L, LOW);
    }

    // acquisition de la valeur variable du potentiomêtre
    x = map(analogRead(A0), 0, 1023, 100, 500);
    periode_ms = (1 / x) * 1000000;
    if(v2==false){
      digitalWrite(S, HIGH);

      delayMicroseconds(periode_ms / 4);

      digitalWrite(S, LOW);

      delayMicroseconds(periode_ms * (3 / 4));

    }
    else {
      digitalWrite(S, HIGH);

      delayMicroseconds(periode_ms * (3 / 4));

      digitalWrite(S, LOW);

      delayMicroseconds(periode_ms / 4);

    }

  }



}
