#include <xc.h>
#include <pic18f458.h>
#include "newxc8_header.h"

#include <string.h> //for string comparison

//for __delay_ms()
#define _XTAL_FREQ 20000000

//LCD pins
#define rs PORTBbits.RB4
#define rw PORTBbits.RB5
#define en PORTBbits.RB6
#define lcd PORTD

//keypad pins
#define r1 PORTCbits.RC0
#define r2 PORTCbits.RC1
#define r3 PORTCbits.RC2
#define r4 PORTCbits.RC3
#define c1 PORTCbits.RC4
#define c2 PORTCbits.RC5
#define c3 PORTCbits.RC6

char password[5]={"7196"}; //Predefined password
char pswd[5]; //Password entered by user
char ch;

//messages to be displayed on LCD
char open_msg[15]="Enter Password";
char welcome_msg[11]="Lock opened";
char close_msg[15]="Wrong Password";
 
char keypad();    //keypad intake
void cmd();       // lcd in command mode
void display();   // lcd is in display mode
void check();     //checking the password
 
unsigned int i;
unsigned int m=0;
unsigned int c=0;
 
void main() 
{
    TRISB=0x00; //output port for LCD pins
    TRISC=0x00; //output port for keypad
    TRISD=0x00; //output port for lcd data
    while(1)
    {   if(c==0)
        {
            lcd=0x38; // LCD display settings
            cmd();
            lcd=0x0E;
            cmd();
            lcd=0x01;
            cmd();
            lcd=0x06;
            cmd();
            lcd=0x80;
            cmd();
            for(int i=0;i<15;i++)
            {
				lcd=open_msg[i];
				display();
            }	
			lcd=0xC0;
            cmd();
			c=1;
		} 
        while(m<4)
        {
            ch=keypad();
			pswd[m]=ch;
			m+=1;
			check();
            __delay_ms(500);
		}	  
               
    }   
}

void check()
{
	if(m>3)
	{
		if(!strcmp(pswd,password))
		{
            lcd=0x01;
            cmd();
            lcd=0x80;
            cmd();
			for(int j=0;j<11;j++)
			{
				lcd=welcome_msg[j];
				display();
			}
		}
		else
		{
            lcd=0x01;
                cmd();
                lcd=0x80;
                cmd();
			for(int j=0;j<15;j++)
			{
				lcd=close_msg[j];
				display();
			}
		}
	}
}
	
 void cmd()
  {
    unsigned char i;
    rs=0;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;
    __delay_ms(10);
   }
 
void display()
  {
    unsigned char i;
    rs=1;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;
    __delay_ms(10);
  }

 
char keypad()
{
    PORTC=0xff;
    while(1) 
    {
        //ROW 1
        r1=0;
        r4=r3=r2=1;
        if(c1==0)
        {
            lcd='*';
            display();
            return '1';
        }
        else if(c2==0)
        {
            lcd='*';
            display();
            return '2';
        }
        else if(c3==0)
        {
            lcd='*';
            display();
			return '3';
        }
        
        //ROW2
        r1=r3=r4=1;
        r2=0;
        if(c1==0)
        {
            lcd='*';
            display();
			return '4';
        }
        else if(c2==0)
        {
            lcd='*';
            display();
			return '5';
        }
        else if(c3==0)
        {
            lcd='*';
            display();
			return '6';
        }
        
        //ROW 3
        r2=r1=r4=1;
        r3=0;
        if(c1==0)
        {
            lcd='*';
            display();
			return '7';
        }
        else if(c2==0)
        {
            lcd='*';
            display();
			return '8';
        }
        else if(c3==0)
        {
            lcd='*';
            display();
			return '9';
        }
        
        //ROW4
        r3=r2=r1=1;
        r4=0;
        if(c1==0)
        {
            lcd='*';
            display();
			return '*';
        }
        else if(c2==0)
        {
            lcd='*';
            display();
			return '0';
        }
        else if(c3==0)
        {
            lcd='*';
            display();
			return '#';
        }
    }
}
 


