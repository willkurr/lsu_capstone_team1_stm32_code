/*
 * methane_detector.h
 *
 *  Created on: Apr 11, 2024
 *      Author: willkurr
 *
 * This library handles methane detection functions: reading the ADC,
 * converting ADC values to methane levels, performing differential measurements
 * using the ADC values from the search sensor, and turning the methane sensor on and off..
 */

#ifndef INC_METHANE_DETECTOR_H_
#define INC_METHANE_DETECTOR_H_

#include "main.h"
#include <stdbool.h>

//Global variables that need to be passed to TouchGFX
// START GLOBAL EXTERN DEFINITIONS
#ifdef __cplusplus
extern "C" {
#endif

extern uint16_t adcValue;					//These two globals are used by TouchGFX in TouchGFX/gui/src/model/model.cpp
extern volatile uint8_t newADCValueReady;

extern volatile uint8_t adcConvInProgress;
extern volatile uint8_t readyToGetADCValue;

#ifdef __cplusplus
}
#endif
// END GLOBAL EXTERN DEFINITIONS

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
void startHandheldADC();
uint16_t getHandheldADCValue();
void startNPointAverageADCRead(uint16_t n);
bool pollForNPointAverageADCRead();
uint16_t getNPointAverageADCValue();



#endif /* INC_METHANE_DETECTOR_H_ */
