#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "methane_detector.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (newMethaneLevelReady) {
		if (modelListener != 0) {
			modelListener->notifyMethaneLevelChanged(methaneLevel);
		}
		newMethaneLevelReady = 0;
	}
}
