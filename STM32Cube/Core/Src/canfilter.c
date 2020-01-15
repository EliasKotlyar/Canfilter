/*
 * canfilter.c
 *
 *  Created on: Jan 15, 2020
 *      Author: eko
 */
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "canfilter.h"
void canloop(CAN_HandleTypeDef *can1, CAN_HandleTypeDef *can2) {
	while (1) {
		// Receive Message from Can1 & send to CAN2:
		if (HAL_CAN_GetRxFifoFillLevel(can1, CAN_RX_FIFO0) != 0) {
			if (HAL_CAN_GetRxMessage(can1, CAN_RX_FIFO0, &RxHeader, RxData)
					!= HAL_OK) {
				/* Reception Error */
				Error_Handler();
			}
			copyData();
			if (HAL_CAN_GetTxMailboxesFreeLevel(can2) != 0) {
				if (HAL_CAN_AddTxMessage(can2, &TxHeader, TxData, &TxMailbox)
						!= HAL_OK) {
					/* Transmission request Error */
					HAL_CAN_ResetError(can2);
					//Error_Handler();
				}
			}

		}
		// Do same on Can2:
		if (HAL_CAN_GetRxFifoFillLevel(can2, CAN_RX_FIFO1) != 0) {
			if (HAL_CAN_GetRxMessage(can2, CAN_RX_FIFO1, &RxHeader, RxData)
					!= HAL_OK) {
				/* Reception Error */
				Error_Handler();
			}
			copyData();
			if (HAL_CAN_GetTxMailboxesFreeLevel(can1) != 0) {
				if (HAL_CAN_AddTxMessage(can1, &TxHeader, TxData, &TxMailbox)
						!= HAL_OK) {
					/* Transmission request Error */
					HAL_CAN_ResetError(can1);
					//Error_Handler();
				}
			}

		}

	}
}
void copyData() {
	memcpy(TxData, RxData, 8);
	TxHeader.DLC = RxHeader.DLC;
	TxHeader.StdId = RxHeader.StdId;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.IDE = CAN_ID_STD;
	filtercan(RxHeader.StdId, TxData);

}
void filtercan(int airbid, uint8_t *data[8]) {
	if (airbid == 0x316) {
		uint8_t d1 = data[2];
		uint8_t d2 = data[3];
		rpm = ((uint16_t) d2 << 8) | d1;
		rpm = rpm / 6.4;
	}
	if(airbid == 0x545){

	}
}
