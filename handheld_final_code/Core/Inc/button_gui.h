/*
 * button_gui.h
 *
 *  Created on: May 1, 2024
 *      Author: admin
 */

#ifndef INC_BUTTON_GUI_H_
#define INC_BUTTON_GUI_H_

#include "main.h"
#include <stdbool.h>

#define BUTTON_NONE		0
#define BUTTON_LEFT 	1
#define BUTTON_RIGHT 	2
#define BUTTON_UP		3
#define BUTTON_DOWN		4
#define BUTTON_SELECT 	5

// START GLOBAL EXTERN DEFINITIONS
#ifdef __cplusplus
extern "C" {
#endif

//Put globals accessed in touchgfx Model.cpp here
extern uint8_t touchgfxButtonPressed;

#ifdef __cplusplus
}
#endif
// END GLOBAL EXTERN DEFINITIONS

uint8_t sampleButtonPress();
uint8_t reportButtonPress(uint8_t currentlyPressed, uint8_t lastButtonPressed);


#endif /* INC_BUTTON_GUI_H_ */
