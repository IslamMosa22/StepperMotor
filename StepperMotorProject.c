/*
 * StepperMotorProject.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Eslam
 */
#include "StepperMotorProject_init.h"
#include "StepperMotorProject_Priv.h"
#include "StepperMotorProject_Config.h"
#include <util/delay.h>



void HStepMotor_voidInitialization()
{

	MDIO_voidSetPortDirection(Motor_Port,0xff);
	MDIO_voidSetPortValue(Motor_Port,arr[0]);

}

void HStepMotor_voidDirAngle(u8 A_u8Direction,u8 A_voidAngle ){

	u8 L_u8counter;
	switch(A_u8Direction)
	{
	case 'L':
		for(L_u8counter = 0;L_u8counter <= A_voidAngle; L_u8counter++){
			if(L_u8counter % 8 == 0 && L_u8counter != 0){
				A_voidAngle -= 8;
				L_u8counter = 0;
			}
			MDIO_voidSetPortValue(Motor_Port,arr[L_u8counter]);
			_delay_ms(50);
		}
		break;

	case 'R':
		for(L_u8counter = 0;L_u8counter < A_voidAngle; L_u8counter++){

			if(L_u8counter % 8 == 0 && L_u8counter != 0){
				A_voidAngle -= 8;
				L_u8counter = 0;
			}

			MDIO_voidSetPortValue(Motor_Port,arr[7 - L_u8counter]);
			_delay_ms(50);
		}
		break;
	}
}
