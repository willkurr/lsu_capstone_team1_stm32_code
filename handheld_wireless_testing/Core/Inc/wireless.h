/*
 * wireless.h
 *
 *  Created on: Apr 12, 2024
 *      Author: willkurr
 */

#ifndef INC_WIRELESS_H_
#define INC_WIRELESS_H_

#include "main.h"

uint8_t Wireless_ReadRegister(uint8_t reg);
void Wireless_WriteRegister(uint8_t reg, uint8_t value);
void Wireless_PowerOn();
void Wireless_PowerDown();
void Wireless_EnableContinuousWave();
void Wireless_DisableContinuousWave();

static void CS_High();
static void CS_Low();
static void CE_High();
static void CE_Low();


#endif /* INC_WIRELESS_H_ */
