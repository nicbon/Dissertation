/*
 * File:   Temperature.c
 * Author: Nicku
 *
 * Created on 25 februarie 2017, 15:59
 */
#include"Temperature.h"

int conversie(unsigned int resistor_value)
 {
	unsigned int res[] ={3002,2939,2877,2814,2752,2689,2627,2564,2502,2439,2377,2328,2280,2232,2184,2136,2087,2039,1991,1943,1895,1857,1820,1782,1745,1707,1670,1632,1595,1557,1520,1490,1461,1432,1403,1374,1344,1315,1286,1257,1228,1205,1182,1159,1136,1114,1091,1068,1045,1022,1000,
  981,963,945,926,908,890,871,853,835,817,802,788,773,759,745,730,716,701,687,673,      ,557,
    463,387,323,272,230,196,167,143,123,106,92,80};
	int result=999;
    unsigned int dif=0,step=0;
	unsigned int table[50];
    unsigned int i,j;
	for ( i=0;i<19;i++)
	{
		if((resistor_value<=res[i]) & (resistor_value>=res[i+1]))	
		{
			dif=res[i]-res[i+1];
			step=dif/50;
			for(unsigned int j=0;j<50;j++)
			{
				
				table[j]=res[i]-j*step;
				
			}
			for(unsigned int j=0;j<50;j++)
			{
				if((resistor_value<=table[j])&(resistor_value>=table[j+1]))
				{
					 result=(i*50+1*j);
					 break;
				}
			}
		}
	}
	return result;
 }


