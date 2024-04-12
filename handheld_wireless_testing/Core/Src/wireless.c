/*
 * wireless.c
 *
 *  Created on: Apr 12, 2024
 *      Author: willkurr
 */

#include "main.h"
#include "wireless.h"

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
