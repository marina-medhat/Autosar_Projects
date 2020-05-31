/*
 * Scheduler.c
 *
 *  Created on: Feb 10, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "../Scheduler/Scheduler.h"

#define TCCR0  *((u8*)0x53)
#define TCNT0  *((u8*)0x52)
#define TIMSK  *((u8*)0x59)
#define SREG   *((u8*)0x5F)

#define INT_OVERFLOW	1
#define GLOBAL_INT		7


extern Task SystemTasks[TASKNUMBERS];

static void Timer0_voidInit(void);
static ErrorStatus Timer0_SetTimeus(u8 Time);
static ErrorStatus Timer0_voidSetCallBack(void(*Copy_pvCallBackPtr)(void));
static void Scheduler(void);
void Timer_CallBack(void);





static void (*TIMER0_pvCallBack)(void)=NULL;

static void Timer0_voidInit(void)
{
	TCCR0|=PRESCALER;
	TIMSK|=INT_OVERFLOW;
	SREG|=1<<GLOBAL_INT;
}

static ErrorStatus Timer0_SetTimeus(u8 Time)
{

	TCNT0=255-Time;
	return ERROR_OK;

}


static ErrorStatus Timer0_voidSetCallBack(void(*Copy_pvCallBackPtr)(void))
{
	if(Copy_pvCallBackPtr!=NULL)
		TIMER0_pvCallBack=Copy_pvCallBackPtr;
	else
		return ERROR_NOK;

	return ERROR_OK;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_pvCallBack!=NULL)
	{
		TIMER0_pvCallBack();
	}
}


void Scheduler_StartOS(void)
{

	Timer0_voidSetCallBack(&Timer_CallBack);

	Timer0_voidInit();

	Timer0_SetTimeus(250);

}


void Scheduler_SuspendTask(u8 TaskID)
{
	SystemTasks[TaskID].State=SUSPENDED;
}

void Scheduler_ResumeTask(u8 TaskID)
{
	SystemTasks[TaskID].State=RUNNING;
}

static void Scheduler(void)
{
	u8 i;
	for(i=0;i<TASKNUMBERS;i++)
	{

		if(SystemTasks[i].State==RUNNING)
		{
			if(SystemTasks[i].FirstDelay==0)
			{
				SystemTasks[i].FirstDelay=SystemTasks[i].Periodicity-1;
				SystemTasks[i].Taskhandler();
			}
			else
			{
				SystemTasks[i].FirstDelay--;
			}
		}
		else
		{
			/*Task Suspended*/
		}

	}

}





void Timer_CallBack(void)
{
	static u8 counter;
	counter++;

	if(4==counter)
	{
		counter=0;
		Scheduler();
	}
}
