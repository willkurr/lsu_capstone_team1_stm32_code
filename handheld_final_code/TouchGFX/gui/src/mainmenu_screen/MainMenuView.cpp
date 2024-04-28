#include <gui/mainmenu_screen/MainMenuView.hpp>


MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
    MainMenuViewBase::setupScreen();
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::updateMethaneLevel(uint16_t newMethaneLevel) {
	Unicode::snprintf(methaneLevelTextAreaBuffer, METHANELEVELTEXTAREA_SIZE, "%d", newMethaneLevel);
	methaneLevelTextArea.invalidate();
}
