/*
 * Lighting.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "../../RTE/RTE.h"
#include "Lighting.h"


ErrorStatus Lighting_Init(void)
{
	return RTE_Call_LampStatus(LAMP_ON);
}

ErrorStatus Lighting_SetLamp(void)
{
	u8 LampStatus;
	ErrorStatus ERROR;

	ERROR=RTE_Read_LampStatus(&LampStatus);

	if(LampStatus==LAMP_ON)
	{
		ERROR|=RTE_Call_LampStatus(LAMP_ON);
	}
	else if(LampStatus==LAMP_OFF)
	{
		ERROR|=RTE_Call_LampStatus(LAMP_OFF);
	}
	else
	{
		ERROR=ERROR_NOK;
	}

	return ERROR;
}

