/*
 * RTE.c
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#include "../Library/std_types.h"

#include "RTE.h"

#include "../BSW/Scheduler/Scheduler.h"
#include "../BSW/DIO/DIO.h"
#include "../BSW/COMM/COMM.h"
#include "../SWC/LeftDoor/LeftDoor.h"
#include "../SWC/Rightdoor/RightDoor.h"
#include "../SWC/DoorContact/DoorContact.h"




u8 LeftDoorStatus =DOOR_OPEN;
u8 RightDoorStatus=DOOR_OPEN;

static void RTE_Runnable(void);
static void RTE_Init(void);


Task SystemTasks[TASKNUMBERS]=
{
		{&RTE_Init,PERIODICITY_5ms,0,RUNNING},
		{&RTE_Runnable,PERIODICITY_10ms,0,RUNNING}
};

/* RTE Sender/Receiver */
ErrorStatus RTE_Write_LeftDoorStatus(u8 Data)
{
	LeftDoorStatus=Data;
	return ERROR_OK;
}

ErrorStatus RTE_Write_RightDoorStatus(u8 Data)
{
	RightDoorStatus=Data;
	return ERROR_OK;
}

ErrorStatus RTE_Read_LeftDoorStatus(u8 *Data)
{
	*Data=LeftDoorStatus;
	return ERROR_OK;
}

ErrorStatus RTE_Read_RightDoorStatus(u8 *Data)
{
	*Data=RightDoorStatus;
	return ERROR_OK;
}

ErrorStatus RTE_Call_SendComm(u8 ID,u8 Data)
{
	return COMM_Send(ID,Data);
}


/* RTE Client/Server */

ErrorStatus RTE_Call_LeftDoorStatus(u8 *Data)
{
	return DIO_GetPinValue(LEFT_SWITCH_PORT,LEFT_SWITCH_PIN,Data);
}

ErrorStatus RTE_Call_RightDoorStatus(u8 *Data)
{
	return DIO_GetPinValue(RIGHT_SWITCH_PORT,RIGHT_SWITCH_PIN,Data);
}




/* OS */


void RTE_Init(void)
{
	COMM_Init();
	DIO_Dimmer_Init();
	LeftDoor_Init();
	RightDoor_Init();
	DoorContact_Init();
	Scheduler_SuspendTask(0);
}

void RTE_Runnable(void)
{
	static u8 counter1;
	counter1++;
	

	LeftDoor_WriteStatus();
	RightDoor_WriteStatus();
	
	if(counter1==6)
	{
		counter1=0;
		COMM_Tx_MainFunction();
		DoorContact_WriteStatus();
	}
	

	
}
