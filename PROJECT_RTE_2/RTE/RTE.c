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

#include "../SWC/Dimmer/Dimmer.h"
#include "../SWC/Lighting/Lighting.h"




u8 LampStatus=LAMP_ON;

static void RTE_Runnable(void);
static void RTE_Init(void);


Task SystemTasks[TASKNUMBERS]=
{
		{&RTE_Init,PERIODICITY_5ms,0,RUNNING},
		{&RTE_Runnable,PERIODICITY_50ms,0,RUNNING}
};

/* RTE Sender/Receiver */

ErrorStatus RTE_Write_LampStatus(u8 Data)
{
	LampStatus=Data;
	return ERROR_OK;
}

ErrorStatus RTE_Read_LampStatus(u8 *Data)
{
	*Data=LampStatus;
	return ERROR_OK;
}



/* RTE Client/Server */


ErrorStatus RTE_Call_ReceiveCOMM(u8 ID, u8 *Data)
{
	return COMM_Receive(ID,Data);
}

ErrorStatus RTE_Call_LampStatus(u8 Data)
{
	return DIO_SetPinValue(LAMP_PORT,LAMP_PIN,Data);
}


/* OS */


void RTE_Init(void)
{
	COMM_Init();
	DIO_Dimmer_Init();
	Dimmer_Init();
	Lighting_Init();
	Scheduler_SuspendTask(0);
}

void RTE_Runnable(void)
{
	COMM_Rx_MainFunction();
	Dimmer_SendLampStatus();
	Lighting_SetLamp();

}
