#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <touchgfx/Color.hpp>
#include "button_gui.h"


MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
    MainMenuViewBase::setupScreen();
    touchgfxCurrentScreen = SCREEN_MAIN;
    currentButtonSelected = SCREENBUTTON_MUTE;
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::updateMethaneLevel(uint16_t newMethaneLevel) {
	Unicode::snprintf(methaneLevelTextAreaBuffer, METHANELEVELTEXTAREA_SIZE, "%d", newMethaneLevel);
	methaneLevelTextArea.invalidate();
}

void MainMenuView::handleButtonPress(uint8_t button) {
	// If this action is a click, then handle it here and return immediately

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
	touchgfx::colortype notHighlightedColor = touchgfx::Color::getColorFromRGB(0,102,153);	//just setting up colors here
	touchgfx::colortype pressedColor = touchgfx::Color::getColorFromRGB(0,152,204);
	touchgfx::colortype borderReleasedColor = touchgfx::Color::getColorFromRGB(0,51,102);
	touchgfx::colortype borderPressedColor = touchgfx::Color::getColorFromRGB(51,102,153);

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
