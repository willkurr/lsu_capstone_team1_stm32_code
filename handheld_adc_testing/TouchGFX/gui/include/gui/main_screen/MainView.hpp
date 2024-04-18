#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    ~MainView() {};
    virtual void setupScreen();

    void updateGFXElements();
    virtual void updateADCValue(uint16_t adcValue);
protected:

private:
    uint8_t count;
};

#endif // MAIN_VIEW_HPP
