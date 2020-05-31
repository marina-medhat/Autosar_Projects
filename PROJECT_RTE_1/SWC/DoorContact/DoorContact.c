/*
 * DoorStatus.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "DoorContact.h"
#include "../../RTE/RTE.h"


ErrorStatus DoorContact_Init(void)
{
	return RTE_Call_SendComm(0,DOOR_OPEN);
}

ErrorStatus DoorContact_WriteStatus(void)
{
	u8 LeftDoorStatus,RightDoorStatus;
	ErrorStatus ERROR;

	ERROR=RTE_Read_LeftDoorStatus(&LeftDoorStatus);
	ERROR|=RTE_Read_RightDoorStatus(&RightDoorStatus);

	if(LeftDoorStatus==DOOR_OPEN || RightDoorStatus==DOOR_OPEN)
	{
		ERROR|= RTE_Call_SendComm(0,DOOR_OPEN);
	}
	else if(LeftDoorStatus==DOOR_CLOSED && RightDoorStatus==DOOR_CLOSED)
	{
		ERROR|= RTE_Call_SendComm(0,DOOR_CLOSED);
	}
	else
	{
		ERROR=ERROR_NOK;
	}

	return ERROR;
}

