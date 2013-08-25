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
 * @file    KL2x/hal_lld.c
 * @brief   Kinetis KL2x HAL Driver subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "ch.h"
#include "hal.h"

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
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
  nvicSetSystemHandlerPriority(HANDLER_SYSTICK, CORTEX_PRIORITY_SYSTICK);
  SysTick->LOAD = CPU_FREQUENCY / CH_FREQUENCY - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;
}

/**
 * @brief   KL2x clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void kl2x_clock_init(void)
{
  /* Disable COP watchdog */
  SIM->COPC = 0;

  /* Enable PORTA */
  SIM->SCGC5 |= 0x00000200;

  /* OUTDIV1 / 2, OUTDIV4 / 2 */
  SIM->CLKDIV1 = 0x10010000;

  /* System oscillator drives 32 kHz clock */
  SIM->SOPT1 &= ~0x000C0000;

  SIM->SOPT2 &= ~0x03000000;
  SIM->SOPT2 |=  0x01010000;

  /* EXTAL0 and XTAL0 */
  PORTA->PCR[18] &= ~0x01000700;
  PORTA->PCR[19] &= ~0x01000700;

  OSC0->CR = 0;

  MCG->C2  = 0x24;
  MCG->C1  = 0x98;
  MCG->C4 &= ~0xE0;
  MCG->C5  = 0x01;
  MCG->C6  = 0;

  /* Check that the source of the FLL reference clock is
     the external reference clock. */
  while ((MCG->S & 0x10) != 0)
    ;

  while ((MCG->S & 0x0C) != 8)      /* wait until external reference */
    ;

  /* PLL selected as MCG source */
  MCG->C6 = 0x40;
  while ((MCG->S & 0x40) == 0)     /* wait until PLL locked */
    ;

  // Switch to PEE mode
  //    Select PLL output (CLKS=0)
  //    FLL external reference divider (FRDIV=3)
  //    External reference clock for FLL (IREFS=0)
  MCG->C1 = 0x18;
  while ((MCG->S & 0x0C) != 0x0C)  /* wait until PLL output */
    ;
}

/**
 * @brief   Platform early initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function is meant to be invoked early during the system
 *          initialization, it is usually invoked from the file
 *          @p board.c.
 *
 * @special
 */
void platform_early_init(void) {

}

/** @} */
