#ifndef SCHEDULER_H_
#define SCEDULER_H_


#define NO_CLOCK_SOURCE					0
#define PRESCALER_DIV_1					1
#define PRESCALER_DIV_8					2
#define PRESCALER_DIV_64				3
#define PRESCALER_DIV_256				4
#define PRESCALER_DIV_1024				5
#define EXTERNAL_CLOCK_ON_FALLING_EDGE	6
#define EXTERNAL_CLOCK_ON_RISING_EDGE	7

#define PRESCALER	PRESCALER_DIV_8

#define PRIORITY_ZERO		0
#define PRIORITY_ONE		1
#define PRIORITY_TWO		2

#define PERIODICITY_5ms		5
#define PERIODICITY_10ms	10
#define PERIODICITY_20ms	20
#define PERIODICITY_50ms	50
#define PERIODICITY_100ms	100



#define TICKTIME	  1		//IN ms
#define TASKNUMBERS	  2

#define RUNNING   	  1U
#define SUSPENDED     2U


typedef struct
{
	void(*Taskhandler)(void);
	u32	Periodicity;
	u32 FirstDelay;
	u8  State;
}Task;


void Scheduler_StartOS(void);
void Scheduler_SuspendTask(u8 TaskID);
void Scheduler_ResumeTask(u8 TaskID);
void Scheduler_CreateTask(u8 Priority,u32 Periodicity,void(*handler)(void), u32 FirstDelay,u8 State);

#endif

