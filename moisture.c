#include<reg51.h>
sbit led=P3^2;
sbit RS=P0^0;
sbit EN=P0^1;
sbit relay=P0^4;
sbit soil=P3^0;
char s[13]="Soil Moisture";
char t[4]="High";
char u[3]="Low";
unsigned int i,j,k,p,q;
void cmdlcd(unsigned char cmd);
void datlcd(unsigned char dat);
//void strlcd(unsigned char *string);
void delay(int x);
void lcdinit();

void main()
{ //led=1;
	//relay=1;
	//soil=1;
	//delay(1000);
	while(1)
	{ cmdlcd(0x38);
    delay(10);
    cmdlcd(0x0E);
    delay(10);
    cmdlcd(0x01);
    delay(10);
		cmdlcd(0x80);
		delay(10);
  	for(i=0;i<13;i++)
		 { datlcd(s[i]);
		  	delay(1);
		 }
		if(soil==1)
		{ led=0;
			relay=0;
			cmdlcd(0x38);
      delay(10);
      cmdlcd(0x0E);
      delay(10);
      cmdlcd(0x01);
      delay(100);
			cmdlcd(0xC0);
			delay(10);
  		for(j=0;j<4;j++)
			{ datlcd(t[j]);
		    delay(1);
			}
			//delay(5000);
		}
		else
		{ led=1;
			relay=1;
			cmdlcd(0x38);
      delay(10);
      cmdlcd(0x0E);
      delay(10);
      cmdlcd(0x01);
      delay(10);
			cmdlcd(0xC0);
			delay(10);
 			for(k=0;k<3;k++)
			 { datlcd(u[k]);
		     delay(1);
			 }
			//delay(5000);
		}			
			
	}
}


void cmdlcd(char cmd)
{  P1=cmd;
   RS=0;
   EN=1;
   delay(10);
   EN=0; 
}
   
void datlcd(unsigned char dat)
{ P1=dat;
	RS=1;
  EN=1;
  delay(10);
  EN=0;
}

void lcdinit()
{ cmdlcd(0x38);
  delay(100);
  cmdlcd(0x0E);
  delay(100);
  cmdlcd(0x01);
  delay(100);
  cmdlcd(0x80);
	delay(100);
}
  
void delay(int x){
	for(p=0;p<x;p++)
	for(q=0;q<7500;q++);
}