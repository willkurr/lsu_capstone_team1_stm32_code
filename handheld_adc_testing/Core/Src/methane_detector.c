/*
 * methane_detector.c
 *
 *  Created on: Apr 11, 2024
 *      Author: willkurr
 */

#include <methane_detector.h>
#include "main.h"

extern ADC_HandleTypeDef hadc1;

/**
 * Reads the 14 bit value of the handheld device ADC.
 * @return the ADC's 14 bit measured value
 */
uint32_t readHandheldADC() {
	HAL_ADC_Start(&hadc1);

	if (HAL_ADC_PollForConversion(&hadc1,1000) != HAL_OK) {
		uint8_t somethingBadHappened = 1;
	}

	return HAL_ADC_GetValue(&hadc1);
}
