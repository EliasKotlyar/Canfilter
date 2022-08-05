/*
 * canfilter.h
 *
 *  Created on: Jan 15, 2020
 *      Author: eko
 */

#ifndef INC_CANFILTER_H_
#define INC_CANFILTER_H_

extern CAN_TxHeaderTypeDef TxHeader;
extern uint8_t TxData[8];
extern uint32_t TxMailbox;
extern CAN_RxHeaderTypeDef RxHeader;
extern uint8_t RxData[8];
extern uint16_t rpm;

void canloop(CAN_HandleTypeDef *can1, CAN_HandleTypeDef *can2);
void filtercan(int airbid, uint8_t *data[8]);

#endif /* INC_CANFILTER_H_ */
