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

#define LAMP_OFF		0
#define LAMP_ON			1

#define LEFT_SWITCH_PORT	PORT_A
#define LEFT_SWITCH_PIN		PIN0

#define RIGHT_SWITCH_PORT	PORT_A
#define RIGHT_SWITCH_PIN	PIN1

#define LAMP_PORT			PORT_A
#define LAMP_PIN			PIN2

/* RTE Sender/Receiver */
ErrorStatus RTE_Write_LeftDoorStatus(u8 Data);
ErrorStatus RTE_Write_RightDoorStatus(u8 Data);
ErrorStatus RTE_Read_LeftDoorStatus(u8 *Data);
ErrorStatus RTE_Read_RightDoorStatus(u8 *Data);




/* RTE Client/Server */
ErrorStatus RTE_Call_SendComm(u8 ID,u8 Data);
ErrorStatus RTE_Call_LeftDoorStatus(u8 *Data);
ErrorStatus RTE_Call_RightDoorStatus(u8 *Data);






#endif /* RTE_H_ */
