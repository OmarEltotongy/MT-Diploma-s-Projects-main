/*
 * pwm.h
 *
 *  Created on: Oct 11, 2022
 *      Author: omare
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PWM_ENABLE_PORT_ID   PORTB_ID
#define PWM_ENABLE_PIN_ID    PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (1*10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
