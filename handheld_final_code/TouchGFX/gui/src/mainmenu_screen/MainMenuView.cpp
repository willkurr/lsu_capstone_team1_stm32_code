#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "button_gui.h"


MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
    MainMenuViewBase::setupScreen();

    //Initialize variables that reflect the state of the screen and main loop of the program.
    touchgfxCurrentScreen = SCREEN_MAIN;
    currentButtonSelected = SCREENBUTTON_MUTE;
    muteStatus = touchgfxIsMuteActive;			//get status of mute from the main loop of program
    loggingStatus = touchgfxIsLoggingActive; 	//get status of logging from the main loop of program
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::updateMethaneLevel(uint16_t newMethaneLevel) {
	if (newMethaneLevel > 10500) {
		Unicode::snprintf(methaneLevelTextAreaBuffer, METHANELEVELTEXTAREA_SIZE, "%s", touchgfx::TypedText(T_OVERRANGETEXT).getText());
	}
	else {
		Unicode::snprintf(methaneLevelTextAreaBuffer, METHANELEVELTEXTAREA_SIZE, "%d", newMethaneLevel);
	}
	methaneLevelTextArea.invalidate();
}

void MainMenuView::handleButtonPress(uint8_t button) {
	// If this action is a click, then handle it here and return immediately
	if (button == BUTTON_SELECT) {
		if (currentButtonSelected == SCREENBUTTON_MUTE) {
			ClickEvent simulatedClick = ClickEvent(ClickEvent::RELEASED,40,220);
			muteFlexButton.setPressed(true);
			muteFlexButton.handleClickEvent(simulatedClick);
		}
		else if (currentButtonSelected == SCREENBUTTON_STARTLOGGING) {
			ClickEvent simulatedClick = ClickEvent(ClickEvent::RELEASED,120,220);
			startLoggingFlexButton.setPressed(true);
			startLoggingFlexButton.handleClickEvent(simulatedClick);
		}
		else if (currentButtonSelected == SCREENBUTTON_SETZERO) {
			ClickEvent simulatedClick = ClickEvent(ClickEvent::RELEASED,200,220);
			setZeroFlexButton.setPressed(true);
			setZeroFlexButton.handleClickEvent(simulatedClick);
		}
		else if (currentButtonSelected == SCREENBUTTON_OPTIONS) {
			ClickEvent simulatedClick = ClickEvent(ClickEvent::RELEASED,278,220);
			optionsMenuFlexButton.setPressed(true);
			optionsMenuFlexButton.handleClickEvent(simulatedClick);
		}
		return;
	}

	// Otherwise, let's handle if we need to change a menu item
	// First, figure out what the current button selected is based on if left or right was pressed.
	if (button == BUTTON_RIGHT) {
		if (currentButtonSelected == SCREENBUTTON_OPTIONS)
			currentButtonSelected = SCREENBUTTON_MUTE;		// Wraparound right
		else
			currentButtonSelected++; // Go right one button
	}
	else if (button == BUTTON_LEFT) {
		if (currentButtonSelected == SCREENBUTTON_MUTE)
			currentButtonSelected = SCREENBUTTON_OPTIONS;	// Wraparound left
		else
			currentButtonSelected--; // Go left one button
	}
	else {
		return;	// The button is not select, left, or right, so we need to return and do nothing.
	}

	// First, set all the button background to the default color
	touchgfx::colortype notHighlightedColor = 	touchgfx::Color::getColorFromRGB(0,102,153);	//just setting up colors here
	touchgfx::colortype pressedColor = 			touchgfx::Color::getColorFromRGB(0,152,204);	//all of these colors are copied from the button colors in the editor
	touchgfx::colortype borderReleasedColor =	touchgfx::Color::getColorFromRGB(0,51,102);
	touchgfx::colortype borderPressedColor = 	touchgfx::Color::getColorFromRGB(51,102,153);

	muteFlexButton.setBoxWithBorderColors(notHighlightedColor, pressedColor, borderReleasedColor, borderPressedColor);	//actually setting the colors
	startLoggingFlexButton.setBoxWithBorderColors(notHighlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
	setZeroFlexButton.setBoxWithBorderColors(notHighlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
	optionsMenuFlexButton.setBoxWithBorderColors(notHighlightedColor, pressedColor, borderReleasedColor, borderPressedColor);

	// Now, highlight the selected button.
	touchgfx::colortype highlightedColor = touchgfx::Color::getColorFromRGB(102,145,172);

	switch (currentButtonSelected) {
		case SCREENBUTTON_MUTE:
			muteFlexButton.setBoxWithBorderColors(highlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
			break;
		case SCREENBUTTON_STARTLOGGING:
			startLoggingFlexButton.setBoxWithBorderColors(highlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
			break;
		case SCREENBUTTON_SETZERO:
			setZeroFlexButton.setBoxWithBorderColors(highlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
			break;
		case SCREENBUTTON_OPTIONS:
			optionsMenuFlexButton.setBoxWithBorderColors(highlightedColor, pressedColor, borderReleasedColor, borderPressedColor);
			break;
	}

	//Finally, invalidate all the buttons.
	muteFlexButton.invalidate();
	startLoggingFlexButton.invalidate();
	setZeroFlexButton.invalidate();
	optionsMenuFlexButton.invalidate();

}

// Called periodically in main.c to force redraw the screen so that buttons don't get stuck.
void MainMenuView::refreshScreen() {
	mainMenuBackground.invalidate();
}

void MainMenuView::muteButtonClicked() {
	muteStatus = !muteStatus;
	touchgfxIsMuteActive = muteStatus; 		// Push the new mute status to the main program.
	if (muteStatus == true) {
		muteFlexButton.setText(touchgfx::TypedText(T_UNMUTEBUTTONTEXT));
		muteFlexButton.invalidate();
	}
	else {
		muteFlexButton.setText(touchgfx::TypedText(T_MUTEBUTTONTEXT));
		muteFlexButton.invalidate();
	}
}

void MainMenuView::startLoggingButtonClicked() {
	loggingStatus = !loggingStatus;
	touchgfxIsLoggingActive = loggingStatus;	// Push the new logging status to the main program.
	if (loggingStatus == true) {
		recordingCircle.setVisible(true);
		recordingCircle.invalidate();
	}
	else {
		recordingCircle.setVisible(false);
		recordingCircle.invalidate();
	}
}

void MainMenuView::setZeroButtonClicked() {
	//If there is no sensor zeroing in progress, send request to main program to zero the sensors
	if (touchgfxZeroRequested == false)
		touchgfxZeroRequested = true;
}

//This function sets the fault light and the 20% LEL lights!!!
//While it only takes the value of the fault light from the Model.cpp tick(), it takes in
//the 20% LEL light status from a global variable in button_gui.h.
void MainMenuView::setFaultLight(bool faultLightStatus) {
	// If fault light needs to be turned on, set the circle color to amber.
	if (faultLightStatus == true) {
		faultStatusCirclePainter.setColor(touchgfx::Color::getColorFromRGB(252, 170, 3));
	}
	// Else, set it back to grey.
	else {
		faultStatusCirclePainter.setColor(touchgfx::Color::getColorFromRGB(209, 209, 209));
	}
	faultStatusCircle.invalidate();	//Redraw the fault light

	// If 20% LEL light needs to be turned on, set the circle color to red.
	if (touchgfxSet20LELLight == true) {
		overRangeAlarmStatusPainter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	}
	// Else, set it back to grey.
	else {
		overRangeAlarmStatusPainter.setColor(touchgfx::Color::getColorFromRGB(209, 209, 209));
	}
	overRangeAlarmStatus.invalidate();	//Redraw the fault light
}
