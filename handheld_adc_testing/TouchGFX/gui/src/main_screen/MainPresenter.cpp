#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{
}

void MainPresenter::activate()
{
}

void MainPresenter::deactivate()
{
}

void MainPresenter::notifyMethaneADCValueChanged(uint16_t newValue) {
	view.updateADCValue(newValue);
}
