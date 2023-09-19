/*
 * dc_motor.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Omar Eltoutongy
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* DC Motor Driver HW Ports and Pins IDs */

#define DC_MOTOR_INPUT1_PORT_ID   PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID    PIN1_ID

#define DC_MOTOR_INPUT2_PORT_ID   PORTB_ID
#define DC_MOTOR_INPUT2_PIN_ID    PIN2_ID



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	NO_ROTATION,CW_ROTATION,CCW_ROTATION
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC Motor:
 * 1. Setup the DC Motor pins directions by use the GPIO driver.
 * 2. Enable Driver.
 * 3. Initialize DC Motor State as Idle.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Set Direction & Speed the DC Motor:
 * 1. Set Direction depending on argument.
 * 2. Set PWM using PWM Driver.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
