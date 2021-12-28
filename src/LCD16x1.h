void Port(char a)
{
	if(a & 1)
		digitalWrite(data_pin_0,HIGH);
	else
		digitalWrite(data_pin_0,LOW);

	if(a & 2)
		digitalWrite(data_pin_1,HIGH);
	else
		digitalWrite(data_pin_1,LOW);

	if(a & 4)
		digitalWrite(data_pin_2,HIGH);
	else
		digitalWrite(data_pin_2,LOW);

	if(a & 8)
		digitalWrite(data_pin_3,HIGH);
	else
		digitalWrite(data_pin_3,LOW);

	if(a & 16)
		digitalWrite(data_pin_4,HIGH);
	else
		digitalWrite(data_pin_4,LOW);

	if(a & 32)
		digitalWrite(data_pin_5,HIGH);
	else
		digitalWrite(data_pin_5,LOW);

	if(a & 64)
		digitalWrite(data_pin_6,HIGH);
	else
		digitalWrite(data_pin_6,LOW);

	if(a & 128)
		digitalWrite(data_pin_7,HIGH);
	else
		digitalWrite(data_pin_7,LOW);
}
void Cmd(char a)
{
  digitalWrite(rs_pin,LOW);
  Port(a);
  digitalWrite(en_pin,HIGH);
  delay(5);
  digitalWrite(en_pin,LOW);
}

void Clear_Display()
{
	  Cmd(1);
}
// Sets the cursor at the begining
void Set_Cursor1() {

    Cmd(0x80);
}
// Sets the cursor after first 8 chars
void Set_Cursor2()
{
	Cmd(0x80 + 0x40);
}

void Init()
{
  Port(0x00);
  digitalWrite(rs_pin,LOW);
  delay(25);
  Cmd(0x30);
  delay(5);
  Cmd(0x30);
  delay(15);
  Cmd(0x30);
  Cmd(0x38);
  Cmd(0x0C);
  Cmd(0x01);
  Cmd(0x06);
}

void Write_Char(char a)
{
   digitalWrite(rs_pin,HIGH);
   Port(a);
   digitalWrite(en_pin,HIGH);
   delay(4);
   digitalWrite(en_pin,LOW);
}
// If the display is 16x1 but the second 8 characters are on new line (most of the chinese displays)
void Write_String8x2(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++) {
        if (i>=8) {
            Set_Cursor2();
            Write_Char(a[8]);
            Write_Char(a[9]);
            Write_Char(a[10]);
            Write_Char(a[11]);
            Write_Char(a[12]);
            Write_Char(a[13]);
            Write_Char(a[14]);
            Write_Char(a[15]);
        } else {
            Write_Char(a[i]);
        }

    }
}
// If the display is regular 16x1
void Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++) {

        Write_Char(a[i]);

    }
}
void Shift_Right()
{
	Cmd(0x1C);
}

void Shift_Left()
{
	Cmd(0x18);
}
