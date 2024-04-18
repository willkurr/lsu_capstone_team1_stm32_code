/*
 * methane_detector.c
 *
 *  Created on: Apr 11, 2024
 *      Author: willkurr
 */

#include "methane_detector.h"
#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern void Error_Handler(void);

/**
 * Starts methane sensor ADC conversion on handheld device and calls HAL_ADC_ConvCpltCallback when done
 */
void startHandheldADC() {
	HAL_ADC_Start_IT(&hadc1);
}

/**
 * Gets the value read by the methane sensor ADC on the handheld. Should be called after startHandheldADC()
 * and after newADCValueReady = 1.
 * @return the 14 bit value read by the ADC
 */
uint16_t getHandheldADCValue() {
	return (uint16_t)HAL_ADC_GetValue(&hadc1);
}


