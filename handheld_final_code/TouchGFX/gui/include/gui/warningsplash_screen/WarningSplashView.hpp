#ifndef WARNINGSPLASHVIEW_HPP
#define WARNINGSPLASHVIEW_HPP

#include <gui_generated/warningsplash_screen/WarningSplashViewBase.hpp>
#include <gui/warningsplash_screen/WarningSplashPresenter.hpp>

class WarningSplashView : public WarningSplashViewBase
{
public:
    WarningSplashView();
    virtual ~WarningSplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WARNINGSPLASHVIEW_HPP
