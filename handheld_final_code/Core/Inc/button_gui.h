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

// Defines for buttons on the PCB
#define BUTTON_NONE		0
#define BUTTON_LEFT 	1
#define BUTTON_RIGHT 	2
#define BUTTON_UP		3
#define BUTTON_DOWN		4
#define BUTTON_SELECT 	5

// Defines for different screens which the program can be in
#define SCREEN_LOADING 0
#define SCREEN_MAIN 1
#define SCREEN_MENU 2

// Define for different buttons on the main menu
#define SCREENBUTTON_MUTE 			0
#define SCREENBUTTON_STARTLOGGING 	1
#define SCREENBUTTON_SETZERO		2
#define SCREENBUTTON_OPTIONS		3

// START GLOBAL EXTERN DEFINITIONS
#ifdef __cplusplus
extern "C" {
#endif

//Put globals accessed in touchgfx Model.cpp here
extern uint8_t touchgfxButtonPressed;
extern uint8_t touchgfxCurrentScreen;
extern bool touchgfxRefreshScreen;
extern bool touchgfxIsMuteActive;
extern bool touchgfxIsLoggingActive;
extern bool touchgfxZeroRequested;
extern bool touchgfxSetFaultLight;
extern bool touchgfxSet20LELLight;

#ifdef __cplusplus
}
#endif
// END GLOBAL EXTERN DEFINITIONS

uint8_t sampleButtonPress();
uint8_t reportButtonPress(uint8_t currentlyPressed, uint8_t lastButtonPressed);


#endif /* INC_BUTTON_GUI_H_ */
