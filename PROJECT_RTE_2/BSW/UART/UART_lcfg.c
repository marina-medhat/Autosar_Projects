#include "../../Library/std_types.h"
#include "UART_lcfg.h"


const UART_Cfg UART_init=
{
		.UART_DataSize			  =UART_DATA_8BITS,
		.UART_BaudRate			  =UART_BAUD_9600,
		.UART_StopBits_Number	  =UART_STOP_1_BIT,
		.UART_ParityType		  =UART_PARITY_DISABLED,
		.UART_Interrupt_Tx_Enable =UART_INT_TX_DISABLE,
		.UART_Interrupt_Rx_Enable =UART_INT_RX_DISABLE
};
