#include <LCD16x2.h>

void setup() {
  for(a=0;a<=7;a++) {
	pinMode(a,OUTPUT);
  }
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Init();
  Write_String("Bigger than 8...");
}

void loop() {

}
