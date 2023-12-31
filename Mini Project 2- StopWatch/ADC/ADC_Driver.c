/*
 * ADC_Driver.c
 *
 *  Created on: Oct 4, 2022
 *      Author: omare
 */
#include "common_macros.h"
#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>
#include "ADC_Driver.h"
#include "std_types.h"

void ADC_init(void)
{
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);

	CLEAR_BIT(ADMUX,MUX0);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);
	CLEAR_BIT(ADMUX,MUX4);

	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);

	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);


}

uint16 ADC_readchannel(uint8 Ch_num)
{
	ADMUX=(ADMUX & 0XE0);
	ADMUX|= (Ch_num & 0X1F);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

