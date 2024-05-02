#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "methane_detector.h"
#include "button_gui.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	// When main.c finishes sampling a methane level, newMethaneLevelReady is set to 1 and this loop detects this.
	// If the main menu screen is active, it will be notified of the new level
	if (newMethaneLevelReady) {
		if (modelListener != 0) {
			modelListener->notifyMethaneLevelChanged(methaneLevel);
		}
		newMethaneLevelReady = 0;
	}

	if (touchgfxButtonPressed != BUTTON_NONE) {
		modelListener->buttonPressed(touchgfxButtonPressed);
		touchgfxButtonPressed = BUTTON_NONE;
	}
}
