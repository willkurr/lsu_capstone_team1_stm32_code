#include <gui/main_screen/MainView.hpp>
#include "BitmapDatabase.hpp"

MainView::MainView() : count(0) {}

void MainView::setupScreen()
{
    updateGFXElements();
}

void MainView::updateGFXElements()
{
	/*
    //Counter text area GFX uptade.
    Unicode::snprintf(countTxtBuffer, 3, "%d", count);
    //Button GFX update and touchable.
    if (count < UPPER_LIMIT)
    {
        buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_ID), Bitmap(BITMAP_UP_BTN_PRESSED_ID));
        buttonUp.setTouchable(true);
    }
    else
    {
        buttonUp.setBitmaps(Bitmap(BITMAP_UP_BTN_DISABLED_ID), Bitmap(BITMAP_UP_BTN_DISABLED_ID));
        buttonUp.setTouchable(false);
    }
    if (count > LOWER_LIMIT)
    {
        buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_ID), Bitmap(BITMAP_DOWN_BTN_PRESSED_ID));
        buttonDown.setTouchable(true);
    }
    else
    {
        buttonDown.setBitmaps(Bitmap(BITMAP_DOWN_BTN_DISABLED_ID), Bitmap(BITMAP_DOWN_BTN_DISABLED_ID));
        buttonDown.setTouchable(false);
    }
    // Invalidate all GFX area, which will result in it being redrawn in next tick.
    countTxt.invalidate();
    buttonUp.invalidate();
    buttonDown.invalidate();
	*/
}
