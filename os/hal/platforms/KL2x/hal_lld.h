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
 * @file    KL2x/hal_lld.h
 * @brief   Kinetis KL2x HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

#include "kl25z.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Defines the support for realtime counters in the HAL.
 */
#define HAL_IMPLEMENTS_COUNTERS TRUE

/**
 * @name    Platform identification
 * @{
 */
#define PLATFORM_NAME           "Kinetis"
/** @} */

/**
 * @brief   Maximum system and core clock (f_SYS) frequency.
 */
#define KINETIS_SYSCLK_MAX      48000000

/**
 * @brief   Maximum bus clock (f_BUS) frequency.
 */
#define KINETIS_BUSCLK_MAX      24000000

/**
 * @name    Internal clock sources
 * @{
 */
#define KINETIS_IRCLK_F         4000000     /**< Fast internal reference clock, factory trimmed. */
#define KINETIS_IRCLK_S         32768       /**< Slow internal reference clock, factory trimmed. */
/** @} */

#define KINETIS_MCG_MODE_FEI  1    /**< FLL Engaged Internal. */
#define KINETIS_MCG_MODE_FEE  2    /**< FLL Engaged External. */
#define KINETIS_MCG_MODE_FBI  3    /**< FLL Bypassed Internal. */
#define KINETIS_MCG_MODE_FBE  4    /**< FLL Bypassed External. */
#define KINETIS_MCG_MODE_PEE  5    /**< PLL Engaged External. */
#define KINETIS_MCG_MODE_PBE  6    /**< PLL Bypassed External. */
#define KINETIS_MCG_MODE_BLPI 7    /**< Bypassed Low Power Internal. */
#define KINETIS_MCG_MODE_BLPE 8    /**< Bypassed Low Power External. */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the MCG/system clock initialization in the HAL.
 */
#if !defined(KINETIS_NO_INIT) || defined(__DOXYGEN__)
#define KINETIS_NO_INIT             FALSE
#endif

/**
 * @brief   MCG mode selection.
 */
#if !defined(KINETIS_MCG_MODE) || defined(__DOXYGEN__)
#define KINETIS_MCG_MODE            KINETIS_MCG_MODE_PEE
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type representing a system clock frequency.
 */
typedef uint32_t halclock_t;

/**
 * @brief   Type of the realtime free counter value.
 */
typedef uint32_t halrtcnt_t;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the current value of the system free running counter.
 * @note    This service is implemented by returning the content of the
 *          DWT_CYCCNT register.
 *
 * @return              The value of the system free running counter of
 *                      type halrtcnt_t.
 *
 * @notapi
 */
#define hal_lld_get_counter_value()         0

/**
 * @brief   Realtime counter frequency.
 * @note    The DWT_CYCCNT register is incremented directly by the system
 *          clock so this function returns STM32_HCLK.
 *
 * @return              The realtime counter frequency of type halclock_t.
 *
 * @notapi
 */
#define hal_lld_get_counter_frequency()     0

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void kl2x_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* _HAL_LLD_H_ */

/** @} */
