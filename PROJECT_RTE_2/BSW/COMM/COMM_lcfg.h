/*
 * COMM_lcfg.h
 *
 *  Created on: Apr 17, 2020
 *      Author: MOSTAFA
 */

#ifndef BSW_COMM_COMM_LCFG_H_
#define BSW_COMM_COMM_LCFG_H_

#define MAX_NUMBER_OF_SIGNALS	6
#define NUMBER_OF_SIGNALS		1
#define NUMBER_OF_PDUS			1




typedef struct
{
	u8 ID;
	u8 Data;
	u8 SignalsID[MAX_NUMBER_OF_SIGNALS];
	u8 NumberOfSignals;
}PDU_t;

typedef struct
{
	u8 Startbit;
	u8 Length;
}Signal_t;


extern PDU_t PDU[NUMBER_OF_PDUS];
extern const Signal_t Signal[NUMBER_OF_SIGNALS];


#endif /* BSW_COMM_COMM_LCFG_H_ */
