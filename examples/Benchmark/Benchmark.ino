/*
  ArcFour Benchmark
  
  created 10 Jun 2014
  by Pascal de Bruijn
  
 */

#include <ArcFour.h>

ArcFour ArcFour;

static const long cycles = 1048576;

unsigned long overhead_start;
unsigned long overhead_stop;
unsigned long overhead_runtime;

unsigned long random_start;
unsigned long random_stop;
unsigned long random_runtime;

unsigned long arcfour_start;
unsigned long arcfour_stop;
unsigned long arcfour_runtime;

float factor;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo and Due
  }
  
  ArcFour.initialize();
  
  for (int i = 0; i < ARCFOUR_MAX; i++)
  {
    ArcFour.seed(i, analogRead(0) % ARCFOUR_MAX);
  }
  
  ArcFour.finalize();
  
  for (int i = 0; i < ARCFOUR_MAX; i++)
  {
    ArcFour.random();
  }
  
  randomSeed(analogRead(0));
}

void loop()
{
  Serial.println("");
  
  
  Serial.print("Overhead   ");
  
  overhead_start = micros();
  for (volatile long i = 0; i < cycles; i++)
    ;
  overhead_stop = micros();
  
  overhead_runtime = overhead_stop - overhead_start;
  Serial.print(overhead_runtime);
  Serial.println("us");
  
  
  Serial.print("Random   ");
  
  random_start = micros();
  for (volatile long i = 0; i < cycles; i++)
    random(256);
  random_stop = micros();
  
  random_runtime = random_stop - random_start;
  Serial.print(random_runtime);
  Serial.println("us");
  
  
  Serial.print("ArcFour    ");
  
  arcfour_start = micros();
  for (volatile long i = 0; i < cycles; i++)
    ArcFour.random();
  arcfour_stop = micros();
  
  arcfour_runtime = arcfour_stop - arcfour_start;
  Serial.print(arcfour_runtime);
  Serial.println("us");

  
  Serial.print("Factor       ");
  
  factor = (float)(random_runtime - overhead_runtime) / (float)(arcfour_runtime - overhead_runtime); 
  Serial.print(factor);
  Serial.println("x");
}
