/*
 * RightDoor.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */


#include "../../Library/std_types.h"
#include "../../RTE/RTE.h"
#include "RightDoor.h"

static ErrorStatus RightSwitch_Debouncing(u8 RightSwitch_State);

ErrorStatus RightDoor_Init(void)
{
	return RTE_Write_RightDoorStatus(DOOR_OPEN);
}

ErrorStatus RightDoor_WriteStatus(void)
{
	u8 RightDoorStatus;
	ErrorStatus ERROR;

	ERROR=RTE_Call_RightDoorStatus(&RightDoorStatus);

	if(ERROR==ERROR_OK)
	ERROR=RightSwitch_Debouncing(RightDoorStatus);
	else
	ERROR=ERROR_NOK;

	if(ERROR==ERROR_OK)
	{
		if(RightDoorStatus==DOOR_CLOSED)
		{
			ERROR|=RTE_Write_RightDoorStatus(DOOR_CLOSED);
		}
		else if(RightDoorStatus==DOOR_OPEN)
		{
			ERROR|=RTE_Write_RightDoorStatus(DOOR_OPEN);
		}
		else
		{
			ERROR=ERROR_NOK;
		}
	}
	else
		ERROR=ERROR_PENDING;

	return ERROR;

}



static ErrorStatus RightSwitch_Debouncing(u8 RightSwitch_State)
{
	static u8 counter,Previous_State=DOOR_OPEN;
	ErrorStatus ERROR;

	if(RightSwitch_State==Previous_State)
		{
			counter++;
		}
		else
		{
			counter=0;
		}
		Previous_State=RightSwitch_State;

		if(counter==5)
		{
			ERROR=ERROR_OK;
		}
		else
		{
			ERROR=ERROR_PENDING;
		}

		return ERROR;

}
