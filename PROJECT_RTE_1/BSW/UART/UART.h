#ifndef _UART_H_
#define _UART_H_


ErrorStatus UART_Init(void);
u8 UART_SendData   (u8 Copy_u8Data);
u8 UART_ReceiveData(u8 * Copy_pu8Data);

#endif
