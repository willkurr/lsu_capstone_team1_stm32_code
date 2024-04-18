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
void MainView::updateADCValue(uint16_t adcValue) {
	boxProgress1.setValue(25);
	Unicode::snprintf(adcrawvalue_textBuffer,ADCRAWVALUE_TEXT_SIZE,"%d",adcValue);
	adcrawvalue_text.invalidate();
	boxProgress1.invalidate();
}
