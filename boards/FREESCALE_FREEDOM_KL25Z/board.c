/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
const PALConfig pal_default_config =
{
  .ports = {
    {
      .port = IOPORT1,
      .pads = {
        PAL_MODE_RESET,           PAL_MODE_ALTERNATIVE_2,     PAL_MODE_ALTERNATIVE_2,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_UNCONNECTED,     PAL_MODE_UNCONNECTED,       PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,           PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT2,
      .pads = {
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_OUTPUT_PUSHPULL,   PAL_MODE_OUTPUT_PUSHPULL,   PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT3,
      .pads = {
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT4,
      .pads = {
        PAL_MODE_RESET,             PAL_MODE_OUTPUT_PUSHPULL,   PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT5,
      .pads = {
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,             PAL_MODE_RESET,
        PAL_MODE_RESET,             PAL_MODE_RESET,
      },
    },
  },
};
#endif

/**
 * @brief   Early initialization code.
 * @details This initialization must be performed just after stack setup
 *          and before any other initialization.
 */
void __early_init(void) {

  kl2x_clock_init();
}

/**
 * @brief   Board-specific initialization code.
 * @todo    Add your board-specific code, if any.
 */
void boardInit(void) {
}
