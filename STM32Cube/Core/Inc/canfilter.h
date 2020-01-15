/*
 * canfilter.h
 *
 *  Created on: Jan 15, 2020
 *      Author: eko
 */

#ifndef INC_CANFILTER_H_
#define INC_CANFILTER_H_

CAN_TxHeaderTypeDef TxHeader;
uint8_t TxData[8];
uint32_t TxMailbox;
uint8_t RxData[8];
uint32_t TxMailbox;
CAN_RxHeaderTypeDef RxHeader;
void canloop(CAN_HandleTypeDef *can1, CAN_HandleTypeDef *can2);
void filtercan(int airbid, uint8_t *data[8]);
uint16_t rpm;

#endif /* INC_CANFILTER_H_ */
