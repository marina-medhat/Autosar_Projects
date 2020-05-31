/*
 * LeftDoor.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */


#include "../../Library/std_types.h"
#include "../../RTE/RTE.h"
#include "LeftDoor.h"

static ErrorStatus LeftSwitch_Debouncing(u8 LeftSwitch_State);

ErrorStatus LeftDoor_Init(void)
{
	return RTE_Write_LeftDoorStatus(DOOR_OPEN);
}

ErrorStatus LeftDoor_WriteStatus(void)
{
	u8 LeftDoorStatus;
	ErrorStatus ERROR;

	ERROR=RTE_Call_LeftDoorStatus(&LeftDoorStatus);

	if(ERROR==ERROR_OK)
	ERROR=LeftSwitch_Debouncing(LeftDoorStatus);
	else
	ERROR=ERROR_NOK;

	if(ERROR==ERROR_OK)
	{
		if(LeftDoorStatus==DOOR_CLOSED)
		{
			ERROR|=RTE_Write_LeftDoorStatus(DOOR_CLOSED);
		}
		else if(LeftDoorStatus==DOOR_OPEN)
		{
			ERROR|=RTE_Write_LeftDoorStatus(DOOR_OPEN);
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



static ErrorStatus LeftSwitch_Debouncing(u8 LeftSwitch_State)
{
	static u8 counter,Previous_State=DOOR_OPEN;
	ErrorStatus ERROR;

	if(LeftSwitch_State==Previous_State)
		{
			counter++;
		}
		else
		{
			counter=0;
		}
		Previous_State=LeftSwitch_State;

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
