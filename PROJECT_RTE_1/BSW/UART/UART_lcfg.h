#ifndef UART_CFG_H_
#define UART_CFG_H_

#define UART_DATA_5BITS				0
#define UART_DATA_6BITS				1
#define UART_DATA_7BITS				2
#define UART_DATA_8BITS				3
#define UART_DATA_9BITS				4


#define UART_PARITY_DISABLED		0
#define UART_PARITY_EVEN			2
#define UART_PARITY_ODD				3

#define UART_BAUD_4800				103
#define UART_BAUD_9600				51
#define UART_BAUD_115200			3

#define UART_STOP_1_BIT				0
#define UART_STOP_2_BIT				1

#define UART_INT_TX_ENABLE			1
#define UART_INT_TX_DISABLE			0
#define UART_INT_RX_ENABLE			1
#define UART_INT_RX_DISABLE			0


typedef struct
{
	u8 UART_DataSize;
	u8 UART_BaudRate;
	u8 UART_StopBits_Number;
	u8 UART_ParityType;
	u8 UART_Interrupt_Tx_Enable;
	u8 UART_Interrupt_Rx_Enable;
}UART_Cfg;


#endif
