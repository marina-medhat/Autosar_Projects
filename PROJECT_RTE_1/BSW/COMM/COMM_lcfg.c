/*
 * COMM.c
 *
 *  Created on: Apr 17, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "COMM_lcfg.h"



PDU_t PDU[NUMBER_OF_PDUS]=
{
		{
				.Data=0,
				.ID=0,
				.NumberOfSignals=1,
				.SignalsID[0]=0
		}



};

const Signal_t Signal[NUMBER_OF_SIGNALS]=
{
		{
				.Startbit=5,
				.Length=1
		}

};
