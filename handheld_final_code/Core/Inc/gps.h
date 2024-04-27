/*
 * gps.h
 *
 *  Created on: Apr 25, 2024
 *      Author: willkurr
 */

#ifndef INC_GPS_H_
#define INC_GPS_H_

#include "main.h"
#include <stdbool.h>


// Externs used by this library and main.c to keep track of the receive status and data received.
extern bool volatile gpsUARTReceiveInProgress;	// True while UART is busy receiving. False when idle or finished.
extern bool volatile checkIfGprmcFound;			// True if the $GPRMC prefix was found in the receieved UART data. Then, check to see if entire message is received in GPS_Poll_For_GPRMC().
extern uint8_t receivedData[128];

// Callbacks
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// Functions
void GPS_Start_UART_Read();
bool GPS_Poll_For_GPRMC(uint8_t *gprmcSentence);
bool GPS_Has_Fix(uint8_t *gprmcSentence);
uint8_t GPS_Get_Hour(uint8_t *gprmcSentence);
uint8_t GPS_Get_Minute(uint8_t *gprmcSentence);
void GPS_Get_Latitude(uint8_t *gprmcSentence, uint8_t *latitudeBuffer);
void GPS_Get_Longitude(uint8_t *gprmcSentence, uint8_t *longitudeBuffer);
void GPS_Get_Date(uint8_t *gprmcSentence, uint8_t *dateBuffer);

#endif /* INC_GPS_H_ */
