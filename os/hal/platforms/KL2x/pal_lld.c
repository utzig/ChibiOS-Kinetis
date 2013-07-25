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

/**
 * @file    KL2x/pal_lld.c
 * @brief   Kinetis KL2x PAL subsystem low level driver.
 *
 * @addtogroup PAL
 * @{
 */

#include "ch.h"
#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   STM32 I/O ports configuration.
 * @details Ports A-D(E, F, G, H) clocks enabled.
 *
 * @param[in] config    the STM32 ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config) {

  (void)config;

#if 0
  SIM->SCGC5 |=  0x00001400;
  SIM->SCGC6 |=  0x05000000;
  SIM->SOPT2 &= ~0x03000000;
  SIM->SOPT2 |=  0x01000000;

  PORTB->PCR18 = 0x00000300;  // TPM2_CH0 enable on PTB18 (red)
  PORTB->PCR19 = 0x00000300;  // TPM2_CH1 enable on PTB19 (green)
  PORTD->PCR1  = 0x00000400;  // TPM0_CH1 enable on PTD1  (blue)

  TPM0->C1V  = 0;
  TPM2->C0V  = 0;
  TPM2->C1V  = 0;

  TPM0->MOD  = 99;
  TPM0->C1SC = 0x00000024;
  TPM2->MOD  = 99;
  TPM2->C0SC = 0x00000024;
  TPM2->C1SC = 0x00000024;
  TPM2->SC   = 0x00000008;
  TPM0->SC   = 0x00000008;
#endif
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode) {

  (void)port;
  (void)mask;
  (void)mode;

}

#endif /* HAL_USE_PAL */

/** @} */
