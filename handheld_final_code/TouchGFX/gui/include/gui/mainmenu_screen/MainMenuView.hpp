#ifndef MAINMENUVIEW_HPP
#define MAINMENUVIEW_HPP

#include <gui_generated/mainmenu_screen/MainMenuViewBase.hpp>
#include <gui/mainmenu_screen/MainMenuPresenter.hpp>

class MainMenuView : public MainMenuViewBase
{
public:
    MainMenuView();
    virtual ~MainMenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateMethaneLevel(uint16_t newMethaneLevel);
    void handleButtonPress(uint8_t button);
    void refreshScreen();
    void muteButtonClicked();
    void startLoggingButtonClicked();
    void setZeroButtonClicked();
    void setFaultLight(bool faultLightStatus);

protected:
    int currentButtonSelected;
    bool muteStatus;
    bool loggingStatus;
};

#endif // MAINMENUVIEW_HPP
