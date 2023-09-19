/*
 * Final_project.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Omar Eltoutongy
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char second=0,min=0,hour=0;

void timer(void)
{
	TCCR1A= (1<<FOC1A);
	TCCR1B =(1<<CS12) | (1<<CS10) |  (1<<WGM12); //Pre-scaler 1024
	TCNT1=0; 					//initial value of timer
	OCR1A=1000; 				//calculated form formula
	TIMSK |= (1<<OCIE1A); 		//Enable interrupt flag
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit

}
void INT0_Reset(void)
{
	DDRD  &= (~(1<<PD2));  // Configure INT1/PD2 as input pin
	PORTD |= (1<<PD2); 		//To activate internal pull up resistor
	// Trigger INT1 with the falling edge
	MCUCR |= (1<<ISC01);
	MCUCR &= ~(1<<ISC00);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
	GICR  |= (1<<INT0);
}
void INT1_Pause(void)
{
	DDRD  &= (~(1<<PD3));  // Configure INT1/PD3 as input pin
	// Trigger INT1 with the raising edge
	MCUCR |= (1<<ISC11);
	MCUCR |= (1<<ISC10);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
	GICR  |=  (1<<INT1);

}
void INT2_Resume(void)
{
	DDRB   &= (~(1<<PB2));   // Configure INT2/PB2 as input pin
	PORTB |= (1<<PB2);		//To activate internal pull up resistor
	MCUCSR &= ~(1<<ISC2);     // Trigger INT2 with the failing edge
	GICR  |= (1<<INT2);
	SREG|=(1<<7);

}
ISR(TIMER1_COMPA_vect)
{
	second++;
	if(second ==60)
	{
		second=0;
		min++;
	}
	if(min==60)
	{
		min=0;
		second=0;
		hour++;
	}
}

ISR(INT0_vect)
{
	second=0;
	min=0;
	hour=0;
	//timer(); // to reset the interrupt counters
}
ISR(INT1_vect)
{
	TCCR1B &= ~(1<<CS10)&~(1<<CS11)&~(1<<CS12);

	//TIMSK &= ~(1<<OCIE1A); 		//disable module interrupt flag
}
ISR(INT2_vect)
{
	TCCR1B =(1<<CS12) | (1<<CS10) |  (1<<WGM12); //Pre-scaler 1024

	//timer();  //to start timer again
}

int main()
{

	DDRC |= 0x0F; //enable the 4 pins of 7 segment to be output
	PORTC &= (0xF0); //to write 0 to last 4bits

	DDRA |=0xFF ;//to activate the bits as output
	PORTA&=0xF3;

	timer();
	INT0_Reset();
	INT1_Pause();
	INT2_Resume();

	while(1)
	{
		PORTA =0X01;
		PORTC = second%10;
		_delay_ms(3);

		PORTA =0X02;
		PORTC = second/10;
		_delay_ms(3);

		PORTA =0X04;
		PORTC = min%10;
		_delay_ms(3);

		PORTA =0X08;
		PORTC = min/10;
		_delay_ms(3);

		PORTA =0X10;
		PORTC = hour%10;
		_delay_ms(3);

		PORTA =0X20;
		PORTC = hour/10;
		_delay_ms(3);

	}

}
