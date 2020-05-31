/*
 * COMM.c
 *
 *  Created on: Apr 17, 2020
 *      Author: MOSTAFA
 */

#include "../../Library/std_types.h"
#include "../UART/UART.h"
#include "COMM_lcfg.h"
#include "COMM.h"

#define FRAME_SIZE	8

static u8 TxBuffer[NUMBER_OF_SIGNALS];
static u8 RxBuffer[NUMBER_OF_SIGNALS];


ErrorStatus COMM_Init(void)
{
	return UART_Init();
}

ErrorStatus COMM_Send(u8 ID,u8 Data)
{
	ErrorStatus ERROR=ERROR_OK;

	if(ID<NUMBER_OF_SIGNALS)
	{
		TxBuffer[ID]=Data;
	}
	else
	{
		ERROR=ERROR_NOK;
	}
	return ERROR;
}

ErrorStatus COMM_Receive(u8 ID,u8 *Data)
{
	ErrorStatus ERROR=ERROR_OK;

	if(ID<NUMBER_OF_SIGNALS)
	{
		*Data=RxBuffer[ID];
	}
	else
	{
		ERROR=ERROR_NOK;
	}

	return ERROR;
}


ErrorStatus COMM_Tx_MainFunction(void)
{
	ErrorStatus ERROR=ERROR_OK;
	u8 CurrentPDU,CurrentSignal;
	u8 CurrentPDU_SignalID;

	for(CurrentPDU=0;CurrentPDU<NUMBER_OF_PDUS;CurrentPDU++)
	{
		PDU[CurrentPDU].Data=0;
		for(CurrentSignal=0;CurrentSignal<PDU[CurrentPDU].NumberOfSignals;CurrentSignal++)
		{
			CurrentPDU_SignalID=PDU[CurrentPDU].SignalsID[CurrentSignal];

			PDU[CurrentPDU].Data|= TxBuffer[CurrentPDU_SignalID] << Signal[CurrentPDU_SignalID].Startbit;
		}

		ERROR|=UART_SendData( ( PDU[CurrentPDU].ID <<6 ) | PDU[CurrentPDU].Data );
	}

	return ERROR;

}


ErrorStatus COMM_Rx_MainFunction(void)
{
	ErrorStatus ERROR=ERROR_OK;

	u8 RxData,PDUID;
	u8 CurrentPDU,CurrentSignal;
	u8 CurrentPDU_SignalID;

	ERROR=UART_ReceiveData(&RxData);

	PDUID=RxData>>6;

	if(ERROR_OK==ERROR)
	{
		for(CurrentPDU=0;CurrentPDU<NUMBER_OF_PDUS;CurrentPDU++)
		{
			if(PDUID==PDU[CurrentPDU].ID)
			{
				for(CurrentSignal=0;CurrentSignal<PDU[CurrentPDU].NumberOfSignals;CurrentSignal++)
				{
					CurrentPDU_SignalID=PDU[CurrentPDU].SignalsID[CurrentSignal];

					RxBuffer[PDU[CurrentPDU].SignalsID[CurrentSignal]]=
							( RxData << \
									( ( FRAME_SIZE ) - ( ( Signal[CurrentPDU_SignalID].Startbit ) + ( Signal[CurrentPDU_SignalID].Length ))))\
									>> ( ( FRAME_SIZE ) - 	( Signal[CurrentPDU_SignalID].Length ) ) ;
				}
			}
		}
	}
	else
	{
		/* Do Nothing  */
	}

	return ERROR;

}

