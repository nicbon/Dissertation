
#include "Config.h"
#include <xc.h>
#ifdef TEMPERATURE_MEASUREMENT

float get_Temp_from_Thermistor(unsigned int resistor_value);
unsigned int get_Thermistor_Value(unsigned int ADC_Counts);
unsigned int get_Temp(void);
#endif