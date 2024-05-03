#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <gui/mainmenu_screen/MainMenuPresenter.hpp>

MainMenuPresenter::MainMenuPresenter(MainMenuView& v)
    : view(v)
{

}

void MainMenuPresenter::activate()
{

}

void MainMenuPresenter::deactivate()
{

}

void MainMenuPresenter::notifyMethaneLevelChanged(uint16_t newMethaneLevel) {
	view.updateMethaneLevel(newMethaneLevel);
}

void MainMenuPresenter::buttonPressed(uint8_t button) {
	view.handleButtonPress(button);
}

void MainMenuPresenter::refreshScreen() {
	view.refreshScreen();
}

void MainMenuPresenter::setFaultLight(bool faultLightStatus) {
	view.setFaultLight(faultLightStatus);
}
