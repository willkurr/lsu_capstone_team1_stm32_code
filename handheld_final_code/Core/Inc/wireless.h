/*
 * wireless.h
 *
 *  Created on: Apr 12, 2024
 *      Author: willkurr
 */

#ifndef INC_WIRELESS_H_
#define INC_WIRELESS_H_

#include "main.h"
#include <stdbool.h>

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

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
void Wireless_Update_RFChannel(uint8_t rfChannel);
void Wireless_Flush_TXPayload();
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
bool Wireless_Check_MAXRT();
void Wireless_Clear_MAXRT();
bool Wireless_Check_TXDS();
bool Wireless_Check_TXFIFO_Full();
bool Wireless_Check_RXDR();
void Wireless_WriteTXPayload(uint8_t payload[], uint16_t pldSize);
void Wireless_ReadRXPayload(uint8_t *rxPayload);
void Wireless_Write_RetrDelandCt(uint8_t retrDel, uint8_t retrCt);
void Wireless_TransmitPld(uint8_t payload[], uint8_t size);
void Wireless_ReceiveMode();
void Wireless_StartTxHandshake();
void Wireless_RxHandshake();
void Wireless_UpdateRxAddress(uint8_t rxUID[], uint8_t dataPipe);
/*
 * end of Caleb's edits;
 */

static void CS_High();
static void CS_Low();
static void CE_High();
static void CE_Low();


#endif /* INC_WIRELESS_H_ */
