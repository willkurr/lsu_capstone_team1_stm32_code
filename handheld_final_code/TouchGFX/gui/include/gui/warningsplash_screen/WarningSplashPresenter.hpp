#ifndef WARNINGSPLASHPRESENTER_HPP
#define WARNINGSPLASHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WarningSplashView;

class WarningSplashPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WarningSplashPresenter(WarningSplashView& v);

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

    virtual ~WarningSplashPresenter() {}

private:
    WarningSplashPresenter();

    WarningSplashView& view;
};

#endif // WARNINGSPLASHPRESENTER_HPP
