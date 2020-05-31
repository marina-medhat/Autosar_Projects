/*
 * main.c

 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#include "Library/std_types.h"
#include "BSW/Scheduler/Scheduler.h"
#include "RTE/RTE.h"


void main(void)
{
	Scheduler_StartOS();
	while(1);
}
