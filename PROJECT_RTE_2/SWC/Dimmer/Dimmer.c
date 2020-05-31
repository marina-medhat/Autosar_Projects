/*
 * Dimmer.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "../../RTE/RTE.h"
#include "Dimmer.h"


ErrorStatus Dimmer_Init(void)
{
	return RTE_Write_LampStatus(LAMP_ON);
}

ErrorStatus Dimmer_SendLampStatus(void)
{
	u8 DoorStatus;
	ErrorStatus ERROR;

	ERROR=RTE_Call_ReceiveCOMM(0,&DoorStatus);

	if(DoorStatus==DOOR_OPEN)
	{
		ERROR|=RTE_Write_LampStatus(LAMP_ON);
	}
	else if(DoorStatus==DOOR_CLOSED)
	{
		ERROR|=RTE_Write_LampStatus(LAMP_OFF);
	}
	else
	{
		ERROR=ERROR_NOK;
	}

	return ERROR;
}
