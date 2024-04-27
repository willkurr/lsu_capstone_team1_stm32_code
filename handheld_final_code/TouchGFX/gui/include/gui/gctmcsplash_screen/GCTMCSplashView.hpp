#ifndef GCTMCSPLASHVIEW_HPP
#define GCTMCSPLASHVIEW_HPP

#include <gui_generated/gctmcsplash_screen/GCTMCSplashViewBase.hpp>
#include <gui/gctmcsplash_screen/GCTMCSplashPresenter.hpp>

class GCTMCSplashView : public GCTMCSplashViewBase
{
public:
    GCTMCSplashView();
    virtual ~GCTMCSplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GCTMCSPLASHVIEW_HPP
