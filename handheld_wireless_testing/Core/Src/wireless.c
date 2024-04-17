/*
 * wireless.c
 *
 *  Created on: Apr 12, 2024
 *      Author: willkurr
 */

#include "main.h"
#include "wireless.h"
#include <stdbool.h>

extern SPI_HandleTypeDef hspi2;

/*
 * Reads a register from the NRF24 chip.
 * @param reg The address of the register to read from
 * @return The value stored in the register at address reg
 */
uint8_t Wireless_ReadRegister(uint8_t reg) {
	uint8_t receivedValue;
	uint8_t command = 0;
	command |= reg;

	CS_Low();
	HAL_SPI_Transmit(&hspi2, &command, 1, 100);
	HAL_SPI_Receive(&hspi2, &receivedValue, 1, 100);
	CS_High();

	return receivedValue;
}

/*
 * Writes a register of the NRF24 chip.
 * @param reg The address of the register to write to.
 * @param value The value to write to the register.
 */
void Wireless_WriteRegister(uint8_t reg, uint8_t value) {
	uint8_t command = 0b00100000;
	command |= reg;

	CS_Low();
	HAL_SPI_Transmit(&hspi2, &command, 1, 100);
	HAL_SPI_Transmit(&hspi2, &value, 1, 100);
	CS_High();
}

void Wireless_WriteValue(uint8_t value) {
	CS_Low();
	HAL_SPI_Transmit(&hspi2, &value, 1, 100);
	CS_High();
}

void Wireless_PowerOn() {
	uint8_t statusRegister = Wireless_ReadRegister(0x00);
	bitset(statusRegister, 1);	// Set the PWR_UP bit (bit 1) of CONFIG register

	Wireless_WriteRegister(0x00,statusRegister);
}

void Wireless_PowerDown() {
	uint8_t statusRegister = Wireless_ReadRegister(0x00);
	bitclear(statusRegister, 1);	// Set the PWR_UP bit (bit 1) of CONFIG register

	Wireless_WriteRegister(0x00,statusRegister);
}

void Wireless_EnableContinuousWave() {
	Wireless_PowerOn();
	HAL_Delay(1);

	uint8_t rfReg = Wireless_ReadRegister(0x06);
	bitset(rfReg,7);	// set CONT_WAVE bit
	bitset(rfReg,4);	// set PLL_LOCK bit
	bitset(rfReg,2);	// set RF_PWR [2:1] bits
	bitset(rfReg,1);
	Wireless_WriteRegister(0x06,rfReg);

	Wireless_WriteRegister(0x05,0);	// Set RF_CH to CH0 (2.4 GHz)

	CE_High();
}

void Wireless_DisableContinuousWave() {
	CE_Low();

	uint8_t rfReg = Wireless_ReadRegister(0x06);
	bitclear(rfReg,7);	// clear CONT_WAVE bit
	bitclear(rfReg,4);	// clear PLL_LOCK bit
	Wireless_WriteRegister(0x06,rfReg);
}

/*
 * Caleb's edits;
 * change if necessary;
 * I'm a peasant;
 */

void Wireless_Update_RFChannel(uint8_t rfChannel) {
	uint8_t rfChReg = Wireless_ReadRegister(0x05);
	rfChReg |= rfChannel;
	rfChReg &= rfChannel;
	Wireless_WriteRegister(0x05, rfChReg);
}

void Wireless_Flush_TXPayload(){
	uint8_t flushTx = 0xE1;
	Wireless_WriteValue(flushTx);
}

void Wireless_CONFIG_RegReset() {
	//reset CONFIG register
	uint8_t configReg = Wireless_ReadRegister(0x00);
	configReg |= 0x08;
	configReg &= 0x08;
	Wireless_WriteRegister(0x00, configReg);
}

void Wireless_ENAA_RegReset() {
	//reset EN_AA register
	uint8_t enAaReg = Wireless_ReadRegister(0x01);
	enAaReg |= 0x3F;
	enAaReg &= 0x3F;
	Wireless_WriteRegister(0x01, enAaReg);
}

void Wireless_ENRXADDR_RegReset() {
	//reset EN_RXADDR register
	uint8_t enRxAddrReg = Wireless_ReadRegister(0x02);
	enRxAddrReg |= 0x03;
	enRxAddrReg &= 0x03;
	Wireless_WriteRegister(0x02, enRxAddrReg);
}

void Wireless_SETUPAW_RegReset() {
	//reset SETUP_AW register
	uint8_t setupAwReg = Wireless_ReadRegister(0x03);
	setupAwReg |= 0x03;
	setupAwReg &= 0x03;
	Wireless_WriteRegister(0x03, setupAwReg);
}

void Wireless_SETUPRETR_RegReset() {
	//reset SETUP_RETR register
	uint8_t setupRetrReg = Wireless_ReadRegister(0x04);
	setupRetrReg |= 0x03;
	setupRetrReg &= 0x03;
	Wireless_WriteRegister(0x04, setupRetrReg);
}

void Wireless_RFCH_RegReset() {
	//reset RF_CH register
	uint8_t rfChReg = Wireless_ReadRegister(0x05);
	rfChReg |= 0x02;
	rfChReg &= 0x02;
	Wireless_WriteRegister(0x05, rfChReg);
}

void Wireless_RFSETUP_RegReset() {
	//reset RF_SETUP register
	uint8_t rfSetupReg = Wireless_ReadRegister(0x06);
	rfSetupReg |= 0x0E;
	rfSetupReg &= 0x0E;
	Wireless_WriteRegister(0x06, rfSetupReg);
}

void Wireless_STATUS_RegReset() {
	//reset STATUS register
	uint8_t statusReg = Wireless_ReadRegister(0x07);
	statusReg |= 0x7E;
	statusReg &= 0x7E;
	Wireless_WriteRegister(0x07, statusReg);
}

void Wireless_RXPWP0_RegReset() {
	//reset RX_PW_P0 register
	uint8_t rxPwP0Reg = Wireless_ReadRegister(0x11);
	rxPwP0Reg |= 0x00;
	rxPwP0Reg &= 0x00;
	Wireless_WriteRegister(0x11, rxPwP0Reg);
}

void Wireless_RXPWP1_RegReset() {
	//reset RX_PW_P1 register
	uint8_t rxPwP1Reg = Wireless_ReadRegister(0x12);
	rxPwP1Reg |= 0x00;
	rxPwP1Reg &= 0x00;
	Wireless_WriteRegister(0x12, rxPwP1Reg);
}

void Wireless_RXPWP2_RegReset() {
	//reset RX_PW_P2 register
	uint8_t rxPwP2Reg = Wireless_ReadRegister(0x13);
	rxPwP2Reg |= 0x00;
	rxPwP2Reg &= 0x00;
	Wireless_WriteRegister(0x13, rxPwP2Reg);
}

void Wireless_RXPWP3_RegReset() {
	//reset RX_PW_P3 register
	uint8_t rxPwP3Reg = Wireless_ReadRegister(0x14);
	rxPwP3Reg |= 0x00;
	rxPwP3Reg &= 0x00;
	Wireless_WriteRegister(0x14, rxPwP3Reg);
}

void Wireless_RXPWP4_RegReset() {
	//reset RX_PW_P4 register
	uint8_t rxPwP4Reg = Wireless_ReadRegister(0x15);
	rxPwP4Reg |= 0x00;
	rxPwP4Reg &= 0x00;
	Wireless_WriteRegister(0x15, rxPwP4Reg);
}

void Wireless_RXPWP5_RegReset() {
	//reset RX_PW_P5 register
	uint8_t rxPwP5Reg = Wireless_ReadRegister(0x16);
	rxPwP5Reg |= 0x00;
	rxPwP5Reg &= 0x00;
	Wireless_WriteRegister(0x16, rxPwP5Reg);
}

void Wireless_DYNPD_RegReset() {
	//reset DYNPD register
	uint8_t dynpdReg = Wireless_ReadRegister(0x1C);
	dynpdReg |= 0x00;
	dynpdReg &= 0x00;
	Wireless_WriteRegister(0x1C, dynpdReg);
}

void Wireless_FEATURE_RegReset() {
	//reset FEATURE register
	uint8_t featureReg = Wireless_ReadRegister(0x1D);
	featureReg |= 0x00;
	featureReg &= 0x00;
	Wireless_WriteRegister(0x1D, featureReg);
}

/*
 * Resets every usable register of the NRF24L01
 */
void Wireless_TotalRegisterReset() {
	Wireless_CONFIG_RegReset();		//reset CONFIG register

	Wireless_ENAA_RegReset();			//reset EN_AA register

	Wireless_ENRXADDR_RegReset();		//reset EN_RXADDR register

	Wireless_SETUPAW_RegReset();		//reset SETUP_AW register

	Wireless_SETUPRETR_RegReset();		//reset SETUP_RETR register

	Wireless_RFCH_RegReset();			//reset RF_CH register

	Wireless_RFSETUP_RegReset();		//reset RF_SETUP register

	Wireless_STATUS_RegReset();			//reset STATUS register

	/* reset RX_ADDR_P0 register
	 * I'm not entirely sure how to do this since the register contains 5 bytes
	 * Should I make an array? Working on that
	 *
	 * uint8_t rxAddrP0Reg;
	 * uint8_t command = 0x00 | 0x0A;

	 * CS_Low();
	 * HAL_SPI_Transmit(&hspi2, &command, 1, 100);
	 * HAL_SPI_Receive(&hspi2, &rxAddrP0Reg, 3, 100);
	 * CS_High();
	 */

	Wireless_RXPWP0_RegReset();			//reset RX_PW_P0 register

	Wireless_RXPWP1_RegReset();			//reset RX_PW_P1 register

	Wireless_RXPWP2_RegReset();			//reset RX_PW_P2 register

	Wireless_RXPWP3_RegReset();			//reset RX_PW_P3 register

	Wireless_RXPWP4_RegReset();			//reset RX_PW_P4 register

	Wireless_RXPWP5_RegReset();			//reset RX_PW_P5 register

	Wireless_DYNPD_RegReset();			//reset DYNPD register

	Wireless_FEATURE_RegReset();		//reset FEATURE register
}

bool Wireless_Check_MAXRT() {
	uint8_t statusReg = Wireless_ReadRegister (0x07);
	uint8_t maxRT = statusReg & 0x10;

	if (maxRT == 0x10) {
		return true;
	}
	else {
		return false;
	}
}

bool Wireless_Check_TXDS() {
	uint8_t statusReg = Wireless_ReadRegister (0x07);
	uint8_t txDS = statusReg & 0x20;

	if (txDS == 0x20) {
		return true;
	}
	else {
		return false;
	}
}

bool Wireless_Check_TXFIFIO_Full() {
	uint8_t statusReg = Wireless_ReadRegister (0x07);
	uint8_t txFIFOFull = statusReg & 0x01;

	if (txFIFOFull == 0x01) {
		return true;
	}
	else {
		return false;
	}
}

void Wireless_WriteTXPayload(uint8_t payload[], int pldSize) {

	uint8_t wTxPldCommand = 0xA0;							//W_TX_PAYLOAD SPI command to write TX pay load
	CS_Low();
	HAL_SPI_Transmit(&hspi2, &wTxPldCommand, 1, 100);		//send write command
	HAL_SPI_Transmit(&hspi2, &payload, pldSize, 100);		//write pay load into FIFO
	CS_High();
}

void Wireless_Write_RetransmitDelayandCount(uint8_t retranDelay, uint8_t retranCount) {
	retranDelay = retranDelay << 4;						//delay determined by bits 7-4 of SETUP register
	uint8_t setupReg = Wireless_ReadRegister(0x04);
	setupReg |= retranDelay;							//set retransmit delay
	setupReg |= retranCount;							//set retransmit count
	Wireless_WriteRegister(0x04, setupReg);
}
/*
 * Initiates wireless connection handshake by the transmitter
 * @return The connection status after the handshake attempt
 */
uint8_t Wireless_StartTxHandshake() {

	CE_Low();

	Wireless_Update_RFChannel(0x01);

	Wireless_Flush_TXPayload();

	Wireless_Check_MAXRT();
	Wireless_Check_TXDS();
	Wireless_Check_TXFIFO_Full();
//read STATUS register
//bitwise AND the register w/ 0001 0000
//if the result is 0x10, MAX_RT (bit 4) is triggered

	uint8_t retransmitDelay = 0b1111;						//4 bit delay value based on data sheet
	uint8_t retransmitCount = 0b1111;						//4 bit count value based on data sheet
	Wireless_Write_RetransmitDelayandCount(retransmitDelay, retransmitCount);
															//if result is 0x00, MAX_RT is not triggered
															//enter transmit mode
	uint8_t configReg = Wireless_ReadRegister(0x00);		//read CONFIG register
	bitclear(configReg,0);									//clear bit 0 (PRIM_RX) of CONFIG register
	Wireless_WriteRegister(0x00,configReg);					// set PRIM_RX to 0

	uint8_t connPld = 0x01;
	Wireless_WriteTxPayload(connPld, 1);

	CE_High();
															//transmit connect packet
															//flush TX FIFO (will auto check for ACK)
															// set CE pin to 1 for > 1us

	uint8_t attempts = 100;									//number of attempts allowed later specified
	uint8_t attemptCounter = 1;								//one connection attempt has been made

	statusReg = Wireless_ReadRegister (0x07);		//read STATUS register
	rfReg = statusReg & 0x10;						//bitwise AND the register w/ 0001 0000
	txDSReg = statusReg & 0x20;						//if the result is 0x10, MAX_RT (bit 4) is triggered
															//if result is 0x00, MAX_RT is not triggered

	/*while (rfReg == 0x10 && attemptCounter < attempts) {	//while MAX_RT is triggered (no ACK) retry connection

		Wireless_WriteRegister(0x07, 0x10);					//reset MAX_RT flag
															//it says to write 1 to the bit (did I do it right?)
		HAL_SPI_Transmit(&hspi2, &wTxPldCommand, 1, 100);	//command to write pay load
		HAL_SPI_Transmit(&hspi2, &connPld, 1, 100);			//re-write pay load

		HAL_SPI_Transmit(&hspi2, &flushTxCommand, 1, 100);	//re-send pay load

		attemptCounter ++;									//increment counter of connection attempts

		statusReg = Wireless_ReadRegister (0x07);			//read STATUS register
		rfReg = statusReg & 0x10;							//check MAX_RT flag
	}
*/
	Wireless_WriteRegister(0x07, 0x10); 					//reset MAX_RT flag

	int connected;											//variable for confirming connection
	if (rfReg == 0x10) {									//if MAX_RT triggered
		connected == 0;									//still not connected
	}
	else {
		connected == 1;									//is connected
	}

	return connected;

}
/*
 * Scans all or the given rf channels to connect with the transmitter
 */
uint8_t Wireless_RxHandshake() {

	uint8_t configReg = Wireless_ReadRegister(0x00);		//read CONFIG register
	bitset(configReg,0);									//set bit 0 (PRIM_RX) of CONFIG register
	Wireless_WriteRegister(0x00,configReg);					// set PRIM_RX to 1

	CE_High();												// set CE pin to 1 for > 1us

	//next step depends on whether the receiver is performing a sweep or is using a pre-stored value for UID and RF Channel

	uint8_t rfChannel;
	uint8_t rfChReg = Wireless_ReadRegister(0x05);
	rfChReg |= rfChannel;
	rfChReg &= rfChannel;
	Wireless_WriteRegister(0x05, rfChReg);

	uint8_t rxUID[5];
	Wireless_UpdateRxAddress(rxUID);

	//for sweep, need to increment RF_CH by one after amount of time while checking for connection by checking RX_DR bit
	/*
	 *remove comments to test sweep
	int delay;
	uint8_t i = 0;
	uint8_t rxDr;

	while (i < 128 && rxDr != 1) {
		uint8_t rfChReg = Wireless_ReadRegister(0x05);
		rfChReg |= i;
		rfChReg &= i;
		Wireless_WriteRegister(0x05, rfChReg);
		HAL_Delay(delay);

		i ++;

		uint8_t statusReg = Wireless_ReadRegister(0x07);
		statusReg &= 0x40;
		statusReg >> 6;
		rxDr = statusReg;
	}
	*/
	Wireless_Status_RegReset();

}
/*
 * Writes the user-specified UID into the RX address register
 * @param rxUID the ID entered by the user to match that of the associated TX
 */
void Wireless_UpdateRxAddress(uint8_t rxUID[]) {
	uint8_t rxAddr[5];
	uint8_t command = 0x0A;

	CS_Low();
	HAL_SPI_Transmit(&hspi2, &command, 1, 100);

	for (int i = 0; i < 5; i++) {
		HAL_SPI_Receive(&hspi2, &rxAddr[i], 1, 100);
		rxAddr[i] |= rxUID[i];
		rxAddr[i] &= rxUID[i];
	}
	CS_High();

	command = 0x2A;

	CS_Low();
	HAL_SPI_Transmit(&hspi2, &command, 1, 100);
	for (int i = 0; i < 5; i++) {
		HAL_SPI_Transmit(&hspi2, &rxAddr[i], 1, 100);
	}
	CS_High();
}
/*
 * end of Caleb's edits;
 */

static void CS_High() {
	HAL_GPIO_WritePin(NRF24_CS_GPIO_Port, NRF24_CS_Pin, GPIO_PIN_SET);
}

static void CS_Low() {
	HAL_GPIO_WritePin(NRF24_CS_GPIO_Port, NRF24_CS_Pin, GPIO_PIN_RESET);
}

static void CE_High() {
	HAL_GPIO_WritePin(NRF24_CE_GPIO_Port, NRF24_CE_Pin, GPIO_PIN_SET);
}

static void CE_Low() {
	HAL_GPIO_WritePin(NRF24_CE_GPIO_Port, NRF24_CE_Pin, GPIO_PIN_RESET);
}
