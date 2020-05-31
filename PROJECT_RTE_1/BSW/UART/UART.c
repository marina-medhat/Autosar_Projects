#include "../../Library/std_types.h"
#include"../../Library/bits.h"

#include "UART.h"
#include "UART_lcfg.h"


#define UDR_T 	*((volatile u8*)0x2C)
#define UDR_R 	*((volatile u8*)0x2C)
#define UCSRA 	*((volatile u8*)0x2B)
#define UCSRB 	*((volatile u8*)0x2A)
#define UCSRC 	*((volatile u8*)0x40)
#define UBRRL 	*((volatile u8*)0x29)
#define UBRRH 	*((volatile u8*)0x40)

extern UART_Cfg UART_init;

#define UCSZ2		2
#define UCSZ1		2			/*DataSize Bits*/
#define UCSZ0		1

#define TXEN		3			/*Transmitting enable bit*/
#define RXEN		4			/*Receiving enable bit*/

#define TXCIE		6			/*Transmitting INT enable bit*/
#define RXCIE		7			/*Receiving INT enable bit*/

#define UCSRC_EN	7			/*To Access UCSRC Register*/

#define PARITY		4			/*Parity Location*/

#define STOPBIT		3			/*StopBit Location*/

ErrorStatus UART_Init(void)
{
	ErrorStatus ERROR=ERROR_OK;

	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);

	switch(UART_init.UART_DataSize)
	{
	case UART_DATA_5BITS:
		CLR_BIT(UCSRB,UCSZ2); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ0);
		break;
	case UART_DATA_6BITS:
		CLR_BIT(UCSRB,UCSZ2); CLR_BIT(UCSRC,UCSZ1); SET_BIT(UCSRC,UCSZ0);
		break;
	case UART_DATA_7BITS:
		CLR_BIT(UCSRB,UCSZ2); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ0);
		break;
	case UART_DATA_8BITS:
		CLR_BIT(UCSRB,UCSZ2); SET_BIT(UCSRC,UCSZ1); SET_BIT(UCSRC,UCSZ0);
		break;
	case UART_DATA_9BITS:
		SET_BIT(UCSRB,UCSZ2); SET_BIT(UCSRC,UCSZ1); SET_BIT(UCSRC,UCSZ0);
		break;
	default: ERROR=ERROR_NOK;
		break;
	}

	UBRRL=UART_BAUD_9600;

	UCSRB|=UART_init.UART_Interrupt_Tx_Enable<<TXCIE;
	UCSRB|=UART_init.UART_Interrupt_Rx_Enable<<RXCIE;

	SET_BIT(UCSRC,UCSRC_EN);

	UCSRC|=UART_init.UART_ParityType<<PARITY;

	UCSRC|=UART_init.UART_StopBits_Number<<STOPBIT;

	return ERROR;
}



u8 UART_SendData(u8 Data)
{
	u8 Error_Status=ERROR_OK;

	UDR_T = Data;
	while(GET_BIT(UCSRA,6)==0);
	return Error_Status;
}


u8 UART_ReceiveData(u8 *Data)
{
	u8 Error_Status=ERROR_OK;

	while(GET_BIT(UCSRA,7)==0);
	*Data=UDR_R;
	return Error_Status;
}





