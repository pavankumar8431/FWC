#include <Arduino.h>

int A = 8;   // To 7447 pin 7

void setup() {
  pinMode(A, OUTPUT);
}

void loop() {

  for(int i = 0; i < 8; i++) {

    int x = (i >> 2) & 1;
    int y = (i >> 1) & 1;
    int z = i & 1;

    // F = X'Y' + YZ
    int F = ((!x) && (!y)) || (y && z);

    if(F == 1)
      digitalWrite(A, HIGH);   // display 1
    else
      digitalWrite(A, LOW);    // display 0

    delay(1500);  // wait 1.5 seconds
  }
}
