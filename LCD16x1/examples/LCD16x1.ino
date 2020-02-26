#include <LCD16x1.h>

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
  //Write_String8x2("0123456789ABCDEF"); // In case of chinese display
  Write_String("0123456789ABCDEF");
}

void loop() {

}
