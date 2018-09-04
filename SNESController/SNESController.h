/* SNES Controller library
 * Copyright (c) 2015 Daniel Veilleux
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 
#ifndef __SNES_CONTROLLER_H__
#define __SNES_CONTROLLER_H__

#include "mbed.h"


/**
* @class SNESController
* @brief Reads the state of an SNES controller and decodes the button presses.
*/
class SNESController {
public:

    /**
     * @enum SNESButton_t
     * @brief The masks of the individual buttons as read from the controller
     */
    enum SNESButton_t
    {
        SNES_BUTTON_B           = 0x0001,
        SNES_BUTTON_Y           = 0x0002,
        SNES_BUTTON_SEL         = 0x0004,
        SNES_BUTTON_START       = 0x0008,
        SNES_BUTTON_UP_ARROW    = 0x0010,
        SNES_BUTTON_DOWN_ARROW  = 0x0020,
        SNES_BUTTON_LEFT_ARROW  = 0x0040,
        SNES_BUTTON_RIGHT_ARROW = 0x0080,
        SNES_BUTTON_A           = 0x0100,
        SNES_BUTTON_X           = 0x0200,
        SNES_BUTTON_L           = 0x0400,
        SNES_BUTTON_R           = 0x0800
    };


    /**
     * @brief Constructs a new object for reading button presses
     *
     * @param  latch
     *         A PinName specifying the latch pin (pin #3)
     * @param  clock
     *         A PinName specifying the clock pin (pin #2)
     * @param  data
     *         A PinName specifying the data pin (pin #4)
     *
     */
    SNESController(PinName latch, PinName clock, PinName data):
        latchPin(latch),
        clockPin(clock),
        dataPin(data) {
            latchPin = 0;
            clockPin = 1;
        }


    /**
     * @brief Reads the current state of the controller and returns a button mask
     *
     * @return
     *     A 16-bit mask containing the states of all of the buttons.
     *     Pressed buttons will have their bits set to 1.
     */
    uint16_t read(void)
    {
        uint32_t mask;
        uint16_t buttons = 0;

        latchPin = 1;
        wait_us(12);
        latchPin = 0;

        wait_us(6);

        for (mask = 0x0001; mask < 0x10000; mask <<= 1)
        {
            clockPin = 0;
            wait_us(6);
    
            // Data is active low.
            if (!dataPin)
            {
                buttons |= mask;
            }

            clockPin = 1;
            wait_us(6);
        }

        return buttons;
    }


    /**
     * @brief Returns true if the specified button is pressed in the given buttonMask
     *
     * @return
     *     True if the specified button is pressed in the mask
     */
    __inline bool pressed(uint16_t buttonMask, SNESButton_t button)
    {
        return (buttonMask & button);    
    }


private:
    DigitalOut latchPin;
    DigitalOut clockPin;
    DigitalIn dataPin;
};

#endif /* #ifndef __SNES_CONTROLLER_H__*/
