#include <reg51.h>
void delay(void);

void main()
{
	unsigned long int i;
	unsigned char ch[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	for(i=0;i<11;i++)
	{
	P1=ch[i];//(0011,1111)
	delay();
	}
}
	
void delay()
{
	TMOD=0x01;//timer 0, MODE1=16bit
	TH0=0x00;
	TL0=0x00;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}

