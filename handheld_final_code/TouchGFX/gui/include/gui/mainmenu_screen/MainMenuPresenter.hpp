#ifndef MAINMENUPRESENTER_HPP
#define MAINMENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainMenuView;

class MainMenuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainMenuPresenter(MainMenuView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainMenuPresenter() {}

    virtual void notifyMethaneLevelChanged(uint16_t newMethaneLevel);

    virtual void buttonPressed(uint8_t button);

    virtual void refreshScreen();

    virtual void setFaultLight(bool faultLightStatus);

private:
    MainMenuPresenter();

    MainMenuView& view;
};

#endif // MAINMENUPRESENTER_HPP
