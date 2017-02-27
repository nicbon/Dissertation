/*
 * File:   Temperature.c
 * Author: Nicku
 *
 * Created on 25 februarie 2017, 15:59
 */
#include"Temperature.h"
#include "ADC.h"

unsigned int get_Thermistor_Value(unsigned int ADC_Counts)
{
 return (ADC_Counts*4.8844)/1.62;  //conversie rezultat conversie in rezistenta   
}

float get_Temp_from_Thermistor(unsigned int resistor_value)
 {
	unsigned int res[] ={3002,2377,1895,1520,1228,1000,817,673,557,
    463,387,323,272,230,196,167,143,123,106,92,80};
    float temp[]={0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};

    float dif=0,step=0;
    unsigned int i,j;
    if(resistor_value>3002)
    {
        return 0;
    }
    else if(resistor_value<80)
    {
        return 100;
    }
    else
    {
        for ( i=0;i<20;i++)
        {

            if((resistor_value<=res[i]) & (resistor_value>=res[i+1]))	
            {
                dif=res[i]-res[i+1];
                step=dif/50;

                for(unsigned int j=0;j<50;j++)
                {
                    if(res[i+1]<=resistor_value)
                    {
                        temp[i+1]-=0.1;
                        res[i+1]+=step;
                    }
                    else
                        break;



                }
                break;
            }
        }
    }
	return temp[i+1];
 }

unsigned int get_Temp(void)
{
    unsigned int thermistor;
    float temp;
    
     thermistor=get_Thermistor_Value(ADC_Get_Value(0));
     temp=get_Temp_from_Thermistor(thermistor)*10;
     return temp;
}