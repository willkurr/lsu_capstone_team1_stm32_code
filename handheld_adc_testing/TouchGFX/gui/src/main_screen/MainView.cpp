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
void MainView::updateADCValue(uint16_t newADCValue, double newVoltage, uint16_t newMethaneLevel) {
	//boxProgress1.setValue(100 * newADCValue/16383);

	//memset(adcRawValueTextBuffer,0,ADCRAWVALUETEXT_SIZE);
	//memset(voltageValueTextBuffer,0,VOLTAGEVALUETEXT_SIZE);
	memset(methaneLevelTextBuffer,0,METHANELEVELTEXT_SIZE);

	//Unicode::snprintf(adcRawValueTextBuffer,ADCRAWVALUETEXT_SIZE,"%d",newADCValue);


	//Unicode::snprintfFloat(voltageValueTextBuffer,VOLTAGEVALUETEXT_SIZE,"%5.3f",(float)newVoltage);


	Unicode::snprintf(methaneLevelTextBuffer,METHANELEVELTEXT_SIZE,"%d",newMethaneLevel);

	//adcRawValueText.invalidate();
	//voltageValueText.invalidate();
	methaneLevelText.invalidate();

	//adcRawValueText.resizeToCurrentText();
	//voltageValueText.resizeToCurrentText();
	methaneLevelText.resizeToCurrentTextWithAlignment();
}
