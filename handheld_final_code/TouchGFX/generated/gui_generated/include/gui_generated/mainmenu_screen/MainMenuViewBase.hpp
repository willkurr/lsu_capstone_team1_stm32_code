/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINMENUVIEWBASE_HPP
#define MAINMENUVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/mainmenu_screen/MainMenuPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class MainMenuViewBase : public touchgfx::View<MainMenuPresenter>
{
public:
    MainMenuViewBase();
    virtual ~MainMenuViewBase();
    virtual void setupScreen();
    virtual void transitionBegins();

    /*
     * Custom Actions
     */
    virtual void action1()
    {
        // Override and implement this function in Screen1
    }
    

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box mainMenuBackground;
    touchgfx::Box menuStatusBarBackground;
    touchgfx::DigitalClock digitalClock;
    touchgfx::FadeAnimator< touchgfx::Circle > recordingCircle;
    touchgfx::PainterRGB565 recordingCirclePainter;
    touchgfx::Box batteryBox2;
    touchgfx::Box batteryBox1;
    touchgfx::TextAreaWithOneWildcard batteryLevelTextArea;
    touchgfx::Image wifiIconImage;
    touchgfx::Line notConnectedLine;
    touchgfx::PainterRGB565 notConnectedLinePainter;
    touchgfx::TextAreaWithOneWildcard methaneLevelTextArea;
    touchgfx::TextAreaWithOneWildcard methaneUnitTextArea;
    touchgfx::Circle faultStatusCircle;
    touchgfx::PainterRGB565 faultStatusCirclePainter;
    touchgfx::Circle overRangeAlarmStatus;
    touchgfx::PainterRGB565 overRangeAlarmStatusPainter;
    touchgfx::TextArea faultStatusTextArea;
    touchgfx::TextArea overRangeAlarmTextArea;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  muteFlexButton;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  startLoggingFlexButton;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  changeUnitFlexButton;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  optionsMenuFlexButton;

    /*
     * Wildcard Buffers
     */
    static const uint16_t BATTERYLEVELTEXTAREA_SIZE = 4;
    touchgfx::Unicode::UnicodeChar batteryLevelTextAreaBuffer[BATTERYLEVELTEXTAREA_SIZE];
    static const uint16_t METHANELEVELTEXTAREA_SIZE = 10;
    touchgfx::Unicode::UnicodeChar methaneLevelTextAreaBuffer[METHANELEVELTEXTAREA_SIZE];
    static const uint16_t METHANEUNITTEXTAREA_SIZE = 6;
    touchgfx::Unicode::UnicodeChar methaneUnitTextAreaBuffer[METHANEUNITTEXTAREA_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 4800;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainMenuViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MAINMENUVIEWBASE_HPP