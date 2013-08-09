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
        /* PTA0*/ PAL_MODE_RESET,           /* PTA1*/ PAL_MODE_ALTERNATIVE_2,   /* PTA2*/ PAL_MODE_ALTERNATIVE_2,
        /* PTA3*/ PAL_MODE_RESET,           /* PTA4*/ PAL_MODE_RESET,           /* PTA5*/ PAL_MODE_RESET,
        /* PTA6*/ PAL_MODE_RESET,           /* PTA7*/ PAL_MODE_RESET,           /* PTA8*/ PAL_MODE_RESET,
        /* PTA9*/ PAL_MODE_RESET,           /*PTA10*/ PAL_MODE_RESET,           /*PTA11*/ PAL_MODE_RESET,
        /*PTA12*/ PAL_MODE_RESET,           /*PTA13*/ PAL_MODE_RESET,           /*PTA14*/ PAL_MODE_RESET,
        /*PTA15*/ PAL_MODE_RESET,           /*PTA16*/ PAL_MODE_RESET,           /*PTA17*/ PAL_MODE_RESET,
        /*PTA18*/ PAL_MODE_UNCONNECTED,     /*PTA19*/ PAL_MODE_UNCONNECTED,     /*PTA20*/ PAL_MODE_RESET,
        /*PTA21*/ PAL_MODE_RESET,           /*PTA22*/ PAL_MODE_RESET,           /*PTA23*/ PAL_MODE_RESET,
        /*PTA24*/ PAL_MODE_RESET,           /*PTA25*/ PAL_MODE_RESET,           /*PTA26*/ PAL_MODE_RESET,
        /*PTA27*/ PAL_MODE_RESET,           /*PTA28*/ PAL_MODE_RESET,           /*PTA29*/ PAL_MODE_RESET,
        /*PTA30*/ PAL_MODE_RESET,           /*PTA31*/ PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT2,
      .pads = {
        /* PTB0*/ PAL_MODE_RESET,           /* PTB1*/ PAL_MODE_RESET,           /* PTB2*/ PAL_MODE_RESET,
        /* PTB3*/ PAL_MODE_RESET,           /* PTB4*/ PAL_MODE_RESET,           /* PTB5*/ PAL_MODE_RESET,
        /* PTB6*/ PAL_MODE_RESET,           /* PTB7*/ PAL_MODE_RESET,           /* PTB8*/ PAL_MODE_RESET,
        /* PTB9*/ PAL_MODE_RESET,           /*PTB10*/ PAL_MODE_RESET,           /*PTB11*/ PAL_MODE_RESET,
        /*PTB12*/ PAL_MODE_RESET,           /*PTB13*/ PAL_MODE_RESET,           /*PTB14*/ PAL_MODE_RESET,
        /*PTB15*/ PAL_MODE_RESET,           /*PTB16*/ PAL_MODE_RESET,           /*PTB17*/ PAL_MODE_RESET,
        /*PTB18*/ PAL_MODE_OUTPUT_PUSHPULL, /*PTB19*/ PAL_MODE_OUTPUT_PUSHPULL, /*PTB20*/ PAL_MODE_RESET,
        /*PTB21*/ PAL_MODE_RESET,           /*PTB22*/ PAL_MODE_RESET,           /*PTB23*/ PAL_MODE_RESET,
        /*PTB24*/ PAL_MODE_RESET,           /*PTB25*/ PAL_MODE_RESET,           /*PTB26*/ PAL_MODE_RESET,
        /*PTB27*/ PAL_MODE_RESET,           /*PTB28*/ PAL_MODE_RESET,           /*PTB29*/ PAL_MODE_RESET,
        /*PTB30*/ PAL_MODE_RESET,           /*PTB31*/ PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT3,
      .pads = {
        /* PTC0*/ PAL_MODE_RESET,           /* PTC1*/ PAL_MODE_RESET,           /* PTC2*/ PAL_MODE_RESET,
        /* PTC3*/ PAL_MODE_RESET,           /* PTC4*/ PAL_MODE_RESET,           /* PTC5*/ PAL_MODE_RESET,
        /* PTC6*/ PAL_MODE_RESET,           /* PTC7*/ PAL_MODE_RESET,           /* PTC8*/ PAL_MODE_RESET,
        /* PTC9*/ PAL_MODE_RESET,           /*PTC10*/ PAL_MODE_RESET,           /*PTC11*/ PAL_MODE_RESET,
        /*PTC12*/ PAL_MODE_RESET,           /*PTC13*/ PAL_MODE_RESET,           /*PTC14*/ PAL_MODE_RESET,
        /*PTC15*/ PAL_MODE_RESET,           /*PTC16*/ PAL_MODE_RESET,           /*PTC17*/ PAL_MODE_RESET,
        /*PTC18*/ PAL_MODE_RESET,           /*PTC19*/ PAL_MODE_RESET,           /*PTC20*/ PAL_MODE_RESET,
        /*PTC21*/ PAL_MODE_RESET,           /*PTC22*/ PAL_MODE_RESET,           /*PTC23*/ PAL_MODE_RESET,
        /*PTC24*/ PAL_MODE_RESET,           /*PTC25*/ PAL_MODE_RESET,           /*PTC26*/ PAL_MODE_RESET,
        /*PTC27*/ PAL_MODE_RESET,           /*PTC28*/ PAL_MODE_RESET,           /*PTC29*/ PAL_MODE_RESET,
        /*PTC30*/ PAL_MODE_RESET,           /*PTC31*/ PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT4,
      .pads = {
        /* PTD0*/ PAL_MODE_RESET,           /* PTD1*/ PAL_MODE_OUTPUT_PUSHPULL, /* PTD2*/ PAL_MODE_RESET,
        /* PTD3*/ PAL_MODE_RESET,           /* PTD4*/ PAL_MODE_RESET,           /* PTD5*/ PAL_MODE_RESET,
        /* PTD6*/ PAL_MODE_RESET,           /* PTD7*/ PAL_MODE_RESET,           /* PTD8*/ PAL_MODE_RESET,
        /* PTD9*/ PAL_MODE_RESET,           /*PTD10*/ PAL_MODE_RESET,           /*PTD11*/ PAL_MODE_RESET,
        /*PTD12*/ PAL_MODE_RESET,           /*PTD13*/ PAL_MODE_RESET,           /*PTD14*/ PAL_MODE_RESET,
        /*PTD15*/ PAL_MODE_RESET,           /*PTD16*/ PAL_MODE_RESET,           /*PTD17*/ PAL_MODE_RESET,
        /*PTD18*/ PAL_MODE_RESET,           /*PTD19*/ PAL_MODE_RESET,           /*PTD20*/ PAL_MODE_RESET,
        /*PTD21*/ PAL_MODE_RESET,           /*PTD22*/ PAL_MODE_RESET,           /*PTD23*/ PAL_MODE_RESET,
        /*PTD24*/ PAL_MODE_RESET,           /*PTD25*/ PAL_MODE_RESET,           /*PTD26*/ PAL_MODE_RESET,
        /*PTD27*/ PAL_MODE_RESET,           /*PTD28*/ PAL_MODE_RESET,           /*PTD29*/ PAL_MODE_RESET,
        /*PTD30*/ PAL_MODE_RESET,           /*PTD31*/ PAL_MODE_RESET,
      },
    },
    {
      .port = IOPORT5,
      .pads = {
        /* PTE0*/ PAL_MODE_RESET,           /* PTE1*/ PAL_MODE_RESET,           /* PTE2*/ PAL_MODE_RESET,
        /* PTE3*/ PAL_MODE_RESET,           /* PTE4*/ PAL_MODE_RESET,           /* PTE5*/ PAL_MODE_RESET,
        /* PTE6*/ PAL_MODE_RESET,           /* PTE7*/ PAL_MODE_RESET,           /* PTE8*/ PAL_MODE_RESET,
        /* PTE9*/ PAL_MODE_RESET,           /*PTE10*/ PAL_MODE_RESET,           /*PTE11*/ PAL_MODE_RESET,
        /*PTE12*/ PAL_MODE_RESET,           /*PTE13*/ PAL_MODE_RESET,           /*PTE14*/ PAL_MODE_RESET,
        /*PTE15*/ PAL_MODE_RESET,           /*PTE16*/ PAL_MODE_RESET,           /*PTE17*/ PAL_MODE_RESET,
        /*PTE18*/ PAL_MODE_RESET,           /*PTE19*/ PAL_MODE_RESET,           /*PTE20*/ PAL_MODE_RESET,
        /*PTE21*/ PAL_MODE_RESET,           /*PTE22*/ PAL_MODE_RESET,           /*PTE23*/ PAL_MODE_RESET,
        /*PTE24*/ PAL_MODE_RESET,           /*PTE25*/ PAL_MODE_RESET,           /*PTE26*/ PAL_MODE_RESET,
        /*PTE27*/ PAL_MODE_RESET,           /*PTE28*/ PAL_MODE_RESET,           /*PTE29*/ PAL_MODE_RESET,
        /*PTE30*/ PAL_MODE_RESET,           /*PTE31*/ PAL_MODE_RESET,
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
