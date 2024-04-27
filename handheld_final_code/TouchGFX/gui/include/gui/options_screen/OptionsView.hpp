#ifndef OPTIONSVIEW_HPP
#define OPTIONSVIEW_HPP

#include <gui_generated/options_screen/OptionsViewBase.hpp>
#include <gui/options_screen/OptionsPresenter.hpp>

class OptionsView : public OptionsViewBase
{
public:
    OptionsView();
    virtual ~OptionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OPTIONSVIEW_HPP
