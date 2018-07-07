#include <LCD16d2.h>

void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Init();
  Write_String("Bigger than 8ddd");
}

void loop() {

}
