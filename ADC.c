#include "ADC.h"


int ADC_Get_Value(char channel)
  {
      ADC_Channel_Init(channel);
  while(ADCON0&0b00000010==0);
  return ADRESL+(ADRESH<<8);
  }
void  ADC_Channel_Init(char channel)
  {
      channel=(channel<<2)|0b00000011;
      ADCON0=0x00;
      ADCON0|=channel;
  }
