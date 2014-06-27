/*
  ArcFour Entropy Seeding Demo
  
  created 10 Jun 2014
  by Pascal de Bruijn
  
 */

#include <Entropy.h>
#include <ArcFour.h>

ArcFour ArcFour;

int ledPin = 13;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo and Due
  }
  
  Entropy.initialize();
  
  ArcFour.initialize();
  
  for (int i = 0; i < ARCFOUR_MAX; i++)
  {
    if (i / 4 % 2)
      digitalWrite(ledPin, LOW);
    else
      digitalWrite(ledPin, HIGH);
    
    ArcFour.seed(i, Entropy.random(WDT_RETURN_BYTE));
  }
  
  ArcFour.finalize();
  
  for (int i = 0; i < ARCFOUR_MAX; i++)
  {
    ArcFour.random();
  }
  
  digitalWrite(ledPin, HIGH);
}

void loop()
{
  Serial.println(ArcFour.random());
  delay(1000);
}

