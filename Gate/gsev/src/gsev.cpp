#include <Arduino.h>

#define X 2
#define Y 3
#define Z 4

#define a 5
#define b 6
#define c 7
#define d 8
#define e 9
#define f 10
#define g 11

void setup() {

  pinMode(X, INPUT_PULLUP);
  pinMode(Y, INPUT_PULLUP);
  pinMode(Z, INPUT_PULLUP);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

// For COMMON ANODE display
void display0() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void display1() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop() {

  int x = digitalRead(X);
  int y = digitalRead(Y);
  int z = digitalRead(Z);

  int F = (!x && !y) || (y && z);

  if (F == 1)
    display1();
  else
    display0();
}
