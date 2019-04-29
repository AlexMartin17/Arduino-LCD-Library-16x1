void Port(char a)
{
	if(a & 1)
		digitalWrite(0,HIGH);
	else 
		digitalWrite(0,LOW);
	
	if(a & 2)
		digitalWrite(1,HIGH);
	else
		digitalWrite(1,LOW);
	
	if(a & 4)
		digitalWrite(2,HIGH);
	else
		digitalWrite(2,LOW);
	
	if(a & 8)
		digitalWrite(3,HIGH);
	else
		digitalWrite(3,LOW);
	
	if(a & 16)
		digitalWrite(4,HIGH);
	else
		digitalWrite(4,LOW);

	if(a & 32)
		digitalWrite(5,HIGH);
	else
		digitalWrite(5,LOW);
	
	if(a & 64)
		digitalWrite(6,HIGH);
	else 
		digitalWrite(6,LOW);
	
	if(a & 128)
		digitalWrite(7,HIGH);
	else
		digitalWrite(7,LOW);
}
void Cmd(char a)
{ 
  digitalWrite(12,LOW);            
  Port(a);             
  digitalWrite(11,HIGH);             
  delay(5);
  digitalWrite(11,LOW);           
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
  digitalWrite(12,LOW);
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
   digitalWrite(12,HIGH);
   Port(a);
   digitalWrite(11,HIGH);
   delay(4);
   digitalWrite(11,LOW);
}
// If the display is 16x1 but second 8 characters are new on new line (most of the chinese displays)
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