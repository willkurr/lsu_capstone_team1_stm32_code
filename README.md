# lsu_capstone_team1_stm32_code
This repository contains all STM32CubeIDE projects as well as some ioc files for microcontroller configurations for LSU capstone team 1: Pragmatics 634 Methane Gas Sensor 2.0.

## Project List
Below is a list of the current projects and their uses:
* Handheld Device: Minimum working example that configures the handheld device peripherals and blinks the LED periodically. IOC file outdated.
* Search Device: Same as Handheld Device project but for te search sensor.
* handheld_display_testing: Minimum working example connecting the ILI9341 display to TouchGFX. Displays the DOOM title screen on the LCD display and sweeps that backlight brightness from 0 to 100% repeatedly.
* handheld_adc_testing: Development of the "methane_detector.c" library for implementing functions related to methane detection such as ADC reads and voltage to methane level calculation.
* handheld_wireless_testing: Development of the "wireless.c" library for allowing control of the NRF24L01 IC.
