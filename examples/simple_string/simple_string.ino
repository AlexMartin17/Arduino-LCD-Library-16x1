#include <LCD16x1.h>

#define rs_pin 12
#define en_pin 11
#define data_pin_0 0
#define data_pin_1 1
#define data_pin_2 2
#define data_pin_3 3
#define data_pin_4 4
#define data_pin_5 5
#define data_pin_6 6
#define data_pin_7 7

void setup() {
  for(int a=0;a<=7;a++) {
	   pinMode(a,OUTPUT);
  }
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Init();
  Write_String("0123456789ABCDEF"); //16x1 Regular display
  //Write_String8x2("0123456789ABCDEF"); //16x1 Chinese display where the second 8 characters are on new line
}

void loop() {

}
