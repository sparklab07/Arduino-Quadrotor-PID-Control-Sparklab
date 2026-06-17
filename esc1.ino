#include <Servo.h>

Servo esc1; //5
Servo esc2; //6

void setup() {
  // put your setup code here, to run once:
  esc1.attach(5); 
  esc2.attach(6); 

  // esc1.writeMicroseconds(2000);
  // esc2.writeMicroseconds(2000);
  // delay(3000);
  esc1.writeMicroseconds(1000);
  esc2.writeMicroseconds(1000);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  esc1.writeMicroseconds(1200);
  esc2.writeMicroseconds(1200);
}





