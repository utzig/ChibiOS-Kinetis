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
#if !KINETIS_NO_INIT
  /* Disable COP watchdog */
  SIM->COPC = 0;

  /* Enable PORTA */
  SIM->SCGC5 |= SIM_SCGC5_PORTA;

  /* The MCGOUTCLK is divided by OUTDIV1 and OUTDIV4:
   * OUTDIV1 (divider for core/system and bus/flash clock)
   * OUTDIV4 (additional divider for bus/flash clock) */
  SIM->CLKDIV1 =
		  SIM_CLKDIV1_OUTDIV1(1) |  /* OUTDIV1 = divide-by-2 */
		  SIM_CLKDIV1_OUTDIV4(1);   /* OUTDIV4 = divide-by-2 */

  /* System oscillator drives 32 kHz clock (OSC32KSEL=0) */
  SIM->SOPT1 &= ~SIM_SOPT1_OSC32KSEL_MASK;

#if KINETIS_MCG_MODE == KINETIS_MCG_MODE_PEE
  /*
   * PLL Enabled External (PEE) MCG Mode
   * 48 MHz core, 24 MHz bus - using 8 MHz crystal with PLL.
   * f_MCGOUTCLK = (OSCCLK / PLL_R) * M
   *             =  8 MHz / 2 * 24 = 96 MHz
   *  PLL_R is the reference divider selected by C5[PRDIV0]
   *  M is the multiplier selected by C6[VDIV0]
   *
   * Then the core/system and bus/flash clocks are divided:
   *   f_SYS = f_MCGOUTCLK / OUTDIV1 = 96 MHz / 2 = 48 MHz
   *   f_BUS = f_MCGOUTCLK / OUTDIV1 / OUTDIV4 = 96 MHz / 4 = 24 MHz
   */

  SIM->SOPT2 =
          SIM_SOPT2_TPMSRC(1) | /* MCGFLLCLK clock or MCGPLLCLK/2 */
          SIM_SOPT2_PLLFLLSEL;  /* PLLFLLSEL=MCGPLLCLK/2 */

  /* EXTAL0 and XTAL0 */
  PORTA->PCR[18] &= ~0x01000700; /* Set PA18 to analog (default) */
  PORTA->PCR[19] &= ~0x01000700; /* Set PA19 to analog (default) */

  OSC0->CR = 0;

  MCG->C2 = /* TODO[CDB] should we set HGO0 for high-gain xtal osc in PEE mode? [see KL25P80M48SF0RM sec 24.5.3.1] */
          MCG_C2_RANGE0(2) |  /* very high frequency range */
          MCG_C2_EREFS0;      /* external reference (using a crystal) */
  MCG->C1 =
          MCG_C1_CLKS_ERCLK |  /* Use ERCLK for MCGCLKOUT */
          MCG_C1_FRDIV(3);     /* Divide ERCLK / 256 for FLL */
  MCG->C4 &= ~(MCG_C4_DMX32 | MCG_C4_DRST_DRS_MASK);
  MCG->C5 = MCG_C5_PRDIV0(1);  /* PLL External Reference Divide by 2 */
  MCG->C6 = 0;  /* PLLS=0: Select FLL as MCG source, not PLL */

  /* Check that the source of the FLL reference clock is
     the external reference clock. */
  while ((MCG->S & MCG_S_IREFST) != 0)
    ;

  while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_ERCLK)
    ;  /* Wait until external reference clock mode is activated*/

  /* PLL selected as MCG source. VDIV0=00000 (Multiply=24). */
  MCG->C6 = MCG_C6_PLLS | MCG_C6_VDIV0(0);
  while ((MCG->S & MCG_S_LOCK0) == 0)  /* wait until PLL locked */
    ;

  // Switch to PEE mode
  //    Select PLL output (CLKS=0)
  //    FLL external reference divider (FRDIV=3)
  //    External reference clock for FLL (IREFS=0)
  MCG->C1 = MCG_C1_CLKS(0) |
            MCG_C1_FRDIV(3);
  while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_PLL)
    ;  /* wait until clock switched to PLL output */

#else /* KINETIS_MCG_MODE != KINETIS_MCG_MODE_PEE */
#error Unimplemented KINETIS_MCG_MODE
#endif /* KINETIS_MCG_MODE != KINETIS_MCG_MODE_PEE */

#endif /* !KINETIS_NO_INIT */
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
