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
void Wireless_WriteValue(uint8_t value);
void Wireless_PowerOn();
void Wireless_PowerDown();
void Wireless_EnableContinuousWave();
void Wireless_DisableContinuousWave();

/*
 * Caleb's edits;
 * change if necessary;
 * I'm a peasant
 */
void Wireless_CONFIG_RegReset();
void Wireless_ENAA_RegReset();
void Wireless_ENRXADDR_RegReset();
void Wireless_SETUPAW_RegReset();
void Wireless_SETUPRETR_RegReset();
void Wireless_RFCH_RegReset();
void Wireless_RFSETUP_RegReset();
void Wireless_STATUS_RegReset();
void Wireless_RXPWP0_RegReset();
void Wireless_RXPWP1_RegReset();
void Wireless_RXPWP2_RegReset();
void Wireless_RXPWP3_RegReset();
void Wireless_RXPWP4_RegReset();
void Wireless_RXPWP5_RegReset();
void Wireless_DYNPD_RegReset();
void Wireless_FEATURE_RegReset();
void Wireless_TotalRegisterReset();
uint8_t Wireless_TxHandshake();
uint8_t Wireless_RxHandshake();
void Wireless_UpdateRxAddress(uint8_t rxUID[]);
/*
 * end of Caleb's edits;
 */

static void CS_High();
static void CS_Low();
static void CE_High();
static void CE_Low();


#endif /* INC_WIRELESS_H_ */
