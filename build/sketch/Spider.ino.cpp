#include <Arduino.h>
#line 1 "d:\\Programming\\Arduino\\Spider\\Spider.ino"

#line 2 "d:\\Programming\\Arduino\\Spider\\Spider.ino"
void setup();
#line 7 "d:\\Programming\\Arduino\\Spider\\Spider.ino"
void loop();
#line 2 "d:\\Programming\\Arduino\\Spider\\Spider.ino"
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello, ugly");
    delay(1000);
}
