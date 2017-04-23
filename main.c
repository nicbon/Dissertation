/******************************************************************************

 The most basic example program to write a line of text in a hd44780 based
 alphanumeric lcd module using our lcd library for pic16 mcus.

 Compiler: Microchip XC8 v1.12 (http://www.microchip.com/xc)
 IDE: Microchip MPLABX

 MCU: PIC16FL1937
 Frequency: 32MHz

                                     NOTICE
                           
NO PART OF THIS WORK CAN BE COPIED, DISTRIBUTED OR PUBLISHED WITHOUT A
WRITTEN PERMISSION FROM EXTREME ELECTRONICS INDIA. THE LIBRARY, NOR ANY PART
OF IT CAN BE USED IN COMMERCIAL APPLICATIONS. IT IS INTENDED TO BE USED FOR
HOBBY, LEARNING AND EDUCATIONAL PURPOSE ONLY. IF YOU WANT TO USE THEM IN
COMMERCIAL APPLICATION PLEASE WRITE TO THE AUTHOR.


WRITTEN BY:
AVINASH GUPTA
me@avinashgupta.com

*******************************************************************************/



#include "Include.h"
// CONFIG
#pragma config FOSC = INTOSC        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
unsigned int i=0;


void main (void)
{unsigned int temp;
    OSCCON=0b01110000;
  LCDInit(LS_NONE);
  TRISDbits.TRISD5=1;
  TRISDbits.TRISD6=1;
  TRISDbits.TRISD7=1;
 
  
  //Write a string
  LCDClear();

  //Initializa the Interrupt on change 
   Init_External_Intterupt(1, NEGATIVE);
   Enable_Global_Interrupts();
 
  
  // ei();
  //  INTCON|=PEIE;
  while(1)
  {  
      
         
         
          LCDClear();
              LCDWriteInt(IOC_Flag,4);
          __delay_ms(100);
      
      
    
    
    
  }

}

