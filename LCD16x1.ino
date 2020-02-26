#include <LCD16x2.h>

void setup() {
  for(a=0;a<=7;a++) {
	pinMode(a,OUTPUT);
  }
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Init();
  Write_String("0123456789ABCDEF");
}

void loop() {

}
