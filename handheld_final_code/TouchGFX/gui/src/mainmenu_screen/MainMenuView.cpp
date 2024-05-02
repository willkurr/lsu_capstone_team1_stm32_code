#include <gui/mainmenu_screen/MainMenuView.hpp>
#include "button_gui.h"


MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
    MainMenuViewBase::setupScreen();
    touchgfxCurrentScreen = SCREEN_MAIN;
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::updateMethaneLevel(uint16_t newMethaneLevel) {
	Unicode::snprintf(methaneLevelTextAreaBuffer, METHANELEVELTEXTAREA_SIZE, "%d", newMethaneLevel);
	methaneLevelTextArea.invalidate();
}
