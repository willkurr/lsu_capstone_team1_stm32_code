#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "methane_detector.h"

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
	// If newADCValueReady is set in the main function, tell TouchGFX it's ready
	if (newADCValueReady) {
		// If there is a modelListener active, notify the view that its ready
		if (modelListener != 0) {
			modelListener->notifyMethaneADCValueChanged(adcValue);
		}

		// Set this back to 0 so main() knows to read another ADC value
		newADCValueReady = 0;
	}
}
