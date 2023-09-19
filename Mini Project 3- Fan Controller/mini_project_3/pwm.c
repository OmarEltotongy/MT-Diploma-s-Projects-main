/*
 * pwm.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Omar Eltoutongy
 */

#include "std_types.h"
#include "common_macros.h" /* For GET_BIT Macro */
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (1*10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0

	/* configure the timer
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	OCR0  = (uint8)(((uint16)255*duty_cycle)/100); /* Divide Duty Cycle by 100 to get percent then multiply with 2^8 */

	GPIO_setupPinDirection(PWM_ENABLE_PORT_ID,PWM_ENABLE_PIN_ID,PIN_OUTPUT); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.
}

