/*
 * button_gui.c
 *
 *  Created on: May 1, 2024
 *      Author: admin
 */

#include "button_gui.h"

/**
 * Samples the GUI buttons to see if a button has been pressed.
 * @return A number corresponding to the button pressed as in button_gui.h, BUTTON_NONE if none pressed.
 */
uint8_t sampleButtonPress() {
	if (HAL_GPIO_ReadPin(BTN_LFT_GPIO_Port, BTN_LFT_Pin)) {
		return BUTTON_LEFT;
	}
	else if (HAL_GPIO_ReadPin(BTN_RGT_GPIO_Port, BTN_RGT_Pin)) {
		return BUTTON_RIGHT;
	}
	else if (HAL_GPIO_ReadPin(BTN_UP_GPIO_Port, BTN_UP_Pin)) {
		return BUTTON_UP;
	}
	else if (HAL_GPIO_ReadPin(BTN_DWN_GPIO_Port, BTN_DWN_Pin)) {
		return BUTTON_DOWN;
	}
	else if (HAL_GPIO_ReadPin(BTN_SEL_GPIO_Port, BTN_SEL_Pin)) {
		return BUTTON_SELECT;
	}
	else {
		return BUTTON_NONE;
	}
}

/**
 * Determines when to report a button as pressed to the GUI. If no button is pressed and the no button was pressed the last time the loop ran,
 * then do nothing. If a button is currently pressed and no button was pressed last time, then wait for it to be released.
 * If no button is pressed and a button was pressed last time, then it has been released and this returns the button that was released.
 * @param currentlyPressed the button that is currently pressed according to sampleButtonPress()
 * @param lastButtonPressed the button that was pressed last time the main loop ran
 * @returns the number of the button released to be propagated to the TouchGFX GUI code
 */
uint8_t reportButtonPress(uint8_t currentlyPressed, uint8_t lastButtonPressed) {
	if (currentlyPressed == BUTTON_NONE && lastButtonPressed != BUTTON_NONE) {
		return lastButtonPressed;
	}
	else {
		return BUTTON_NONE;
	}
}
