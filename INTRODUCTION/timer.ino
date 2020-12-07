int const pin = 10;
unsigned int delta, time = 0, timer, last_timer = 0, seuil = 500;
bool led = true, last_led;

void setup()
{
    pinMode(pin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    timer = millis();
    time = time + timer - last_timer;
    last_timer = timer;

    last_led = led;
    if (time > seuil)
    {
        time = 0;
        led = !led;
    }

    if (last_led != led)
    {
        digitalWrite(pin, led);
    }
}