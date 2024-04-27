#ifndef GCTMCSPLASHPRESENTER_HPP
#define GCTMCSPLASHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GCTMCSplashView;

class GCTMCSplashPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GCTMCSplashPresenter(GCTMCSplashView& v);

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

    virtual ~GCTMCSplashPresenter() {}

private:
    GCTMCSplashPresenter();

    GCTMCSplashView& view;
};

#endif // GCTMCSPLASHPRESENTER_HPP
