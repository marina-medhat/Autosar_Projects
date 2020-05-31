/*
 * COMM_lcfg.h
 *
 *  Created on: Apr 17, 2020
 *      Author: MOSTAFA
 */

#ifndef BSW_COMM_COMM_H_
#define BSW_COMM_COMM_H_

ErrorStatus COMM_Init(void);

ErrorStatus COMM_Send(u8 ID,u8 Data);
ErrorStatus COMM_Receive(u8 ID,u8 *Data);

ErrorStatus COMM_Tx_MainFunction(void);
ErrorStatus COMM_Rx_MainFunction(void);


#endif /* BSW_COMM_COMM_LCFG_H_ */
