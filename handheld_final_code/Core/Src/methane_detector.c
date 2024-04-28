/*
 * methane_detector.c
 *
 *  Created on: Apr 11, 2024
 *      Author: willkurr
 */

#include "methane_detector.h"
#include "main.h"
#include <stdbool.h>
#include <math.h>

extern ADC_HandleTypeDef hadc1;
extern void Error_Handler(void);

// Externs
uint8_t volatile adcConvInProgress = 0;
uint8_t volatile readyToGetADCValue = 0;

// Globals in the scope of this file
uint16_t currentSample = 0;
uint16_t numSamples = 0;
uint32_t adcSum = 0;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if (hadc == &hadc1) {
		readyToGetADCValue = 1;
		adcConvInProgress = 0;
	}
}

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

/**
 * Starts an average measurement of n samples of the ADC.
 * @param n The number of samples to average
 */
void startNPointAverageADCRead(uint16_t n) {
	currentSample = 0;
	numSamples = n;
	adcSum = 0;

	startHandheldADC();
	adcConvInProgress = 1;
}

/**
 * Polls for the completion of the n point average started in startNPointAverageADCRead.
 * Must be called continuously to advance the ADC n point sample measurement.
 * @return true if the n-point adc read is complete, false otherwise
 */
bool pollForNPointAverageADCRead() {
	// If the ADC value is ready, get it and add it to the adcSum and increment current sample.
	if (readyToGetADCValue) {
		readyToGetADCValue = 0;
		adcSum += getHandheldADCValue();
		currentSample++;
	}
	// If the ADC value is not ready and no conversion is in progress, start a conversion.
	else if (!adcConvInProgress) {
		adcConvInProgress = 1;
		startHandheldADC();
	}

	if (currentSample == numSamples) return true;

	return false;
}

/**
 * Gets the result of the last completed n point average read.
 * Call this after pollForNPointAverageADCRead returns true.
 * @return the 14-bit n-point averaged ADC value.
 */
uint16_t getNPointAverageADCValue() {
	return adcSum / numSamples;
}


/**
 * Converts a 14-bit ADC sensor reading to a methane level in ppm.
 * @param adcReading the 14-bit ADC reading from a Figaro 2611 sensor
 * @param Ro the Figaro 2611 sensor's resistance in 5,000 ppm methane in ohms
 * @returns the methane level in an integer number of ppm
 */
uint16_t convertADCToMethane(uint16_t adcReading, double Ro) {
	// Convert ADC reading to floating point voltage
	double VDD = 3.293;	 // voltage divider supply voltage (volts)
	double adcVoltage = VDD * ((double)adcReading / 16383.0);	// 16383 = 2^14 - 1

	double RL = 10000;	 // voltage divider circuit load resistance (ohms)


	double methaneLevelPPM = 1.0/(pow((adcVoltage*RL)/(40.28*Ro*(VDD-adcVoltage)),2.33208955));
	return (uint16_t)round(methaneLevelPPM);
}
