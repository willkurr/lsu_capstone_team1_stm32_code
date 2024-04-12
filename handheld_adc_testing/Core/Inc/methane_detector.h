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

uint32_t readHandheldADC();


#endif /* INC_METHANE_DETECTOR_H_ */
