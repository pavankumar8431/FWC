#include <Arduino.h>

void disp_7474(int D, int C, int B, int A)
{
  digitalWrite(2, A); // LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); // MSB
}

void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() 
{
  disp_7474(0, 1, 1, 1);
  delay(1000);

 disp_7474(0, 1, 1, 1);
  delay(1000);

  disp_7474(0, 1, 0, 0);
  delay(1000);

  disp_7474(0, 1, 1, 1);
  delay(1000);

  disp_7474(0, 1, 0, 0);
  delay(1000);

  disp_7474(1, 1, 1, 1);
  delay(300);
}
