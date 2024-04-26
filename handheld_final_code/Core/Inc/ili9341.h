/*
 * ili9341.h
 *

MIT License

Copyright (c) 2020 Kotestu Yamamoto
Copyright (c) 2024 William Curry

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

 */

#ifndef INC_ILI9341_H_
#define INC_ILI9341_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include <stdbool.h>

#define GUI_WIDTH 320
#define GUI_HEIGHT 240

void ILI9341_Init(void);
void ILI9341_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y);
void ILI9341_DrawBitmap(uint16_t w, uint16_t h, uint8_t *s);
void ILI9341_WritePixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_EndOfDrawBitmap(void);
void ILI9341_SetDisplayBrightness(TIM_HandleTypeDef* htim, uint8_t percent);

//Global variables used for writing framebuffer when number of bytes is too large for a single DMA transfer
extern uint8_t *framebufferLocation;	//holds the location of the framebuffer in case it is too large for ILI9341_DrawBitmap() to draw at once
extern uint32_t bytesLeft;				//holds the number of bytes left to be written in case ILI9341_DrawBitmap() can't draw entire buffer at once
extern bool framebufferTooBig;
extern bool isTransmitting;
extern uint16_t width;
extern uint16_t height;
extern uint16_t currentLine;

#ifdef __cplusplus
}
#endif

#endif /* INC_ILI9341_H_ */
