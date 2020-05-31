/*
 * RTE.h
 *
 *  Created on: Apr 2, 2020
 *      Author: MOSTAFA
 */

#ifndef RTE_H_
#define RTE_H_

#define DOOR_OPEN		1
#define DOOR_CLOSED		0

#define TWO_DOORS_CLOSED	0xAA
#define ONE_DOOR_OPENED		0xBB

#define LAMP_OFF		0
#define LAMP_ON			1

#define LEFT_SWITCH_PORT	PORT_A
#define LEFT_SWITCH_PIN		PIN0

#define RIGHT_SWITCH_PORT	PORT_A
#define RIGHT_SWITCH_PIN	PIN1

#define LAMP_PORT			PORT_A
#define LAMP_PIN			PIN2

/* RTE Sender/Receiver */

ErrorStatus RTE_Write_LampStatus(u8 Data);
ErrorStatus RTE_Read_LampStatus(u8 *Data);

/* RTE Client/Server */

ErrorStatus RTE_Call_LampStatus(u8 Data);
ErrorStatus RTE_Call_ReceiveCOMM(u8 ID, u8 *Data);






#endif /* RTE_H_ */
