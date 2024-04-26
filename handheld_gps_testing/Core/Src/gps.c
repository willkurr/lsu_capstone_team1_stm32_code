/*
 * gps.c
 *
 *  Created on: Apr 25, 2024
 *      Author: willkurr
 */

#include "main.h"
#include "gps.h"
#include <stdbool.h>
#include <string.h>

// Initializing externs from gps.h
bool volatile gpsUARTReceiveInProgress = false;
bool volatile checkIfGprmcFound = false;
uint8_t receivedData[128];

extern UART_HandleTypeDef huart4;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	gpsUARTReceiveInProgress = false;
	checkIfGprmcFound = true;
}

/**
 * Starts reading a chunk of data from the GPS module. Call GPS_Poll_For_GPRMC() periodically after this
 * to get the
 */
void GPS_Start_UART_Read() {
	gpsUARTReceiveInProgress = true;
	__HAL_UART_CLEAR_FLAG(&huart4,UART_CLEAR_OREF);		//clear overrun caused by GPS sending data all the time
	HAL_UART_Receive_IT(&huart4, &receivedData, 127);
}

/**
 * Polls to see if the GPRMC sentence was received, and if so, writes the sentence to the buffer provided.
 * @param gprmcSentence Buffer which the gprmc sentence is written to when received
 * @returns true if a sentence was successfully received, false otherwise
 */
bool GPS_Poll_For_GPRMC(uint8_t *gprmcSentence) {
	char *gprmcPrefix = "$GPRMC";

	//If the received data contains the GPRMC prefix, $GPRMC, we at least have the start of the sentence.
	if (strstr(&receivedData,gprmcPrefix) != NULL) {
		// GPRMC prefix was detected. Now check to see if entire message is present.
		uint8_t *gprmcLocation = strstr(&receivedData,gprmcPrefix);		// Get the starting address of the sentence (where the $ is)
		uint8_t *gprmcEnd = strchr(gprmcLocation, 13);  				// Get the ending address of the sentence (where the <CR> or \r is (13 in ASCII))

		//If true, then the whole sentence was received, we can now extract the substring which exists from receivedData+7 to gprmcEnd
		if (gprmcEnd != NULL) {
			uint8_t i = 0;
			for (uint8_t *addr = gprmcLocation+7; addr < gprmcEnd; addr++) {
				gprmcSentence[i] = *addr;
				i++;
			}
		}
		//Otherwise, we missed the <CR> and need to try again.
		else {
			return false;
		}
	}
	// Otherwise, we missed the GPRMC sentence entirely and need to start again.
	else {
		return false;
	}

	return true;
}

/**
 * Parses a GPRMC NMEA sentence to check if the GPS module has a fix and can be used for location data.
 * Checks the second field of the RMC sentence. 'A' indicates fix and 'V' indicates no fix.
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @return True if GPS has fix, false otherwise.
 */
bool GPS_Has_Fix(uint8_t *gprmcSentence) {
	//Get the address of the status character, after the first comma of the RMC sentence
	uint8_t *fixStatus = strchr(gprmcSentence,',') + 1;
	if (*fixStatus == 'A') {
		return true;
	}
	return false;
}

/**
 * Parses a GPRMC NMEA sentence to get the current hour of the time in 24 hr format, UTC.
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @return the current hour of the time in UTC
 */
uint8_t GPS_Get_Hour(uint8_t *gprmcSentence) {
	uint8_t hour = 0;
	hour = 10*(*(gprmcSentence) - 48) + (*(gprmcSentence+1) - 48);	//converts ascii to numerical digits, and sums tens and ones digit of time
	return hour;
}

/**
 * Parses a GPRMC NMEA sentence to get the current minute of the time.
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @return the current minute of the time
 */
uint8_t GPS_Get_Minute(uint8_t *gprmcSentence) {
	uint8_t minute = 0;
	minute = 10*(*(gprmcSentence+2) - 48) + (*(gprmcSentence+3) - 48);	//converts ascii to numerical digits, and sums tens and ones digit of time
	return minute;
}

/**
 * Parses a GPRMC NMEA sentence to get the latitude in the format Degreesminutes.decimal in the form ddmm.mmmm
 * where dd is the degrees latitude and mm.mmmm is the 2 digit minutes and 4 decimal places.
 * Only call this function if GPS_Has_Fix returns true!
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @param latitudeBuffer pointer to buffer where the latitude will be stored in ddmm.mmmm format (must be at least 9 characters long)
 */
void GPS_Get_Latitude(uint8_t *gprmcSentence, uint8_t *latitudeBuffer) {
	//First, find the starting location of the latitude. It is after the second comma.
	uint8_t *latitudeStart = strchr(gprmcSentence,',') + 1;
	latitudeStart = strchr(latitudeStart,',') + 1;		//get pointer to the first address after the second comma

	// for each character in the latitudeBuffer, put the corresponding character of the latitude in the buffer
	for (int i = 0; i < 9; i++) {
		latitudeBuffer[i] = *(latitudeStart + i);
	}
}

/**
 * Parses a GPRMC NMEA sentence to get the longitude in the format Degreesminutes.decimal in the form dddmm.mmmm
 * where ddd is the degrees longitude and mm.mmmm is the 2 digit minutes and 4 decimal places.
 * Only call this function if GPS_Has_Fix returns true!
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @param longitudeBuffer pointer to buffer where the longitude will be stored in dddmm.mmmm format (must be at least 10 characters long)
 */
void GPS_Get_Longitude(uint8_t *gprmcSentence, uint8_t *longitudeBuffer) {
	//Get the starting location of longitude, after the fourth comma.
	//cursed stacked function calls... it works
	uint8_t *longitudeStart = strchr(gprmcSentence,',') + 1;
	longitudeStart = strchr(longitudeStart,',') + 1;
	longitudeStart = strchr(longitudeStart,',') + 1;
	longitudeStart = strchr(longitudeStart,',') + 1;	//gets starting address of character after fourth comma in sentence

	// for each character in the longitudeBuffer, put the corresponding character of the latitude in the buffer
	for (int i = 0; i < 10; i++) {
		longitudeBuffer[i] = *(longitudeStart + i);
	}
}

/**
 * Parses a GPRMC NMEA sentence to get the date in the format DDMMYY (where the day is determined with UTC time)
 * @param gprmcSentence pointer to the string holding the gprmc sentence
 * @param dateBuffer pointer to buffer where the date will be stored in DDMMYY format (must be at least 6 characters long)
 */
void GPS_Get_Date(uint8_t *gprmcSentence, uint8_t *dateBuffer) {
	// Date starts after eighth comma
	uint8_t *dateStart = strchr(gprmcSentence,',') + 1;

	for (int i = 0; i < 7; i++) {
		dateStart = strchr(dateStart,',') + 1;
	}

	// for each character in the dateBuffer, put the corresponding character of the date in the buffer
	for (int i = 0; i < 6; i++) {
		dateBuffer[i] = *(dateStart + i);
	}
}
