#include <gui/main_screen/MainView.hpp>
#include "BitmapDatabase.hpp"

MainView::MainView() : count(0) {}

void MainView::setupScreen()
{
    updateGFXElements();
}

void MainView::updateGFXElements() {}

/*
 * Updates the screen with the adcValue in the adcrawvalue wildcard.
 * @param adcValue The 14-bit adc value to insert
 */
void MainView::updateADCValue(uint16_t newValue) {
	boxProgress1.setValue(100 * newValue/16383);
	Unicode::snprintf(adcrawvalue_textBuffer,ADCRAWVALUE_TEXT_SIZE,"%d",newValue);
	adcrawvalue_text.invalidate();
	adcrawvalue_text.resizeToCurrentText();
}
