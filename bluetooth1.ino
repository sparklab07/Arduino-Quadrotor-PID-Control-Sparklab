#include <SoftwareSerial.h>

SoftwareSerial bluetooth1(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  bluetooth1.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (bluetooth1.available()) {
    Serial.write(bluetooth1.read());
  }
}