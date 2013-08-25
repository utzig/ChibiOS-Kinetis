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

/*
 * STM32F0xx drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 *
 * IRQ priorities:
 * 3...0       Lowest...Highest.
 *
 * DMA priorities:
 * 0...3        Lowest...Highest.
 */

#define KL2x_MCUCONF

/*
 * HAL driver system settings.
 */

/*
 * I2C driver system settings.
 */
#define KINETIS_I2C_USE_I2C0                  FALSE
#define KINETIS_I2C_USE_I2C1                  FALSE

/*
 * SERIAL driver system settings.
 */
#define KINETIS_SERIAL_USE_UART0              TRUE
#define KINETIS_SERIAL_USE_UART1              FALSE
#define KINETIS_SERIAL_USE_UART2              FALSE
#define KINETIS_SERIAL_UART0_PRIORITY         3
#define KINETIS_SERIAL_UART1_PRIORITY         3
#define KINETIS_SERIAL_UART2_PRIORITY         3
