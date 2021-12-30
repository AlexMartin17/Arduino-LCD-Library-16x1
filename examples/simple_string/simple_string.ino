#include <LCD16x1.h>

void setup() {
  for(int a=0;a<=7;a++) {
	   pinMode(a,OUTPUT);
  }
  pinMode(11,OUTPUT); //en pin
  pinMode(12,OUTPUT); //rs pin
  Init();
  Write_String("0123456789ABCDEF"); //16x1 Regular display
  //Write_String8x2("0123456789ABCDEF"); //16x1 Chinese display where the second 8 characters are on new line
}

void loop() {

}
