/*
 * File:   External_Interrupt.c
 * Author: Nicku
 *
 * Created on 19 martie 2017, 14:53
 */

#include "Custom_Interrupts.h"
//#include <xc.h>
//#include "Globals.h"
#include "lcd_hd44780_pic16.h"



void Enable_Global_Interrupts(void)
{
    
    ei();           //enable global interrupts
    INTCONbits.PEIE=1;   //enable peripheral interrupts
}
void Init_External_Intterupt(unsigned char channel, Edge_Type edge)
{
        TRISB=TRISB|channel;
        ANSELB=ANSELB&(~channel);
        INTCONbits.IOCIE=1;  //enable interrupt on change
        WPUB=WPUB|channel;  //enable pullup for selected chanell
    if(edge==1)  //select positive edge
    {
        
        IOCBP=IOCBP|channel;  
        IOCBN=IOCBN&(~channel);
         
    }
    else if(edge==0)   //select negative edge
    {
        
        IOCBN=IOCBN|channel;
        IOCBP=IOCBP&(~channel);
       
    }
    else if(edge==2)  //select both positive and negative edge
    {
        
        IOCBP=IOCBP|channel;
        IOCBN=IOCBN|channel;
      
    }
    else return;
    return;
}

void interrupt ISR(void)
{
    if(IOCBFbits.IOCBF0==1)
    {IOCBFbits.IOCBF0=0;
    IOC_Flag=~IOC_Flag;
    }
}

