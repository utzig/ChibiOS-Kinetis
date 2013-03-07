/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012,2013 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ch.h"
#include "hal.h"

#define ADC_GRP1_NUM_CHANNELS   5
#define ADC_GRP1_BUF_DEPTH      8

//#define ADC_GRP2_NUM_CHANNELS   8
//#define ADC_GRP2_BUF_DEPTH      16

static ADCConfig adccfg1 = {0, 0};

static adcsample_t samples1[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];
//static adcsample_t samples2[ADC_GRP2_NUM_CHANNELS * ADC_GRP2_BUF_DEPTH];

/*
 * ADC streaming callback.
 */
/*size_t nx = 0, ny = 0;
static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n) {

  (void)adcp;
  if (samples2 == buffer) {
    nx += n;
  }
  else {
    ny += n;
  }
}*/

static void adcerrorcallback(ADCDriver *adcp, adcerror_t err) {

  (void)adcp;
  (void)err;

  palSetPad(PORT11, P11_LED4);
  chSysHalt();
}

/*
 * ADC conversion group.
 * Mode:        Linear buffer, 8 samples of 5 channels, SW triggered.
 * Channels:    ADC_CHN_VRL, ADC_CHN_VREF25, ADC_CHN_VREF50,
 *              ADC_CHN_VREF75, ADC_CHN_VRH.
 *
 * NOTE: The configuration of a sequence is very complex in this ADC
 * implementation. Configurations are meant to be generated by the
 * SPC5 Studio visual configuration tool and not be written manually.
 * Writing complex sequences manually requires ad deep knowledge of both
 * the EQADC peripheral and the driver implementation.
 */
static const adccommand_t adcgrpcfg1_commands[ADC_GRP1_NUM_CHANNELS *
                                              ADC_GRP1_BUF_DEPTH] = {
  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRL),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF25),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF50),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VREF75),

  EQADC_CONV_BN_ADC0 | EQADC_CONV_LST_64 | EQADC_CONV_CAL |
  EQADC_CONV_FMT_RJU | EQADC_CONV_CONFIG_STD | EQADC_CONV_MSG_RFIFO(0) |
  EQADC_CONV_CHANNEL(ADC_CHN_VRH)
};

static const ADCConversionGroup adcgrpcfg1 = {
  FALSE,
  ADC_GRP1_NUM_CHANNELS,
  NULL,
  adcerrorcallback,
  EQADC_CFCR_SSE | EQADC_CFCR_MODE_SWSS,
  ADC_GRP1_BUF_DEPTH,
  adcgrpcfg1_commands
};

/*
 * ADC conversion group.
 * Mode:        Continuous, 16 samples of 8 channels, SW triggered.
 * Channels:    IN7, IN8, IN7, IN8, IN7, IN8, Sensor, VBat/2.
 */
/*static const ADCConversionGroup adcgrpcfg2 = {
  TRUE,
  ADC_GRP2_NUM_CHANNELS,
  adccallback,
  adcerrorcallback,
};*/

/*
 * Red LEDs blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (TRUE) {
    palSetPad(PORT11, P11_LED1);
    chThdSleepMilliseconds(500);
    palClearPad(PORT11, P11_LED1);
    chThdSleepMilliseconds(500);
  }
  return 0;
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Setting up analog inputs used by the demo.
   */
/*  palSetGroupMode(GPIOC, PAL_PORT_BIT(1) | PAL_PORT_BIT(2),
                  0, PAL_MODE_INPUT_ANALOG);*/

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Activates the ADC1 driver and the temperature sensor.
   */
  adcStart(&ADCD1, &adccfg1);

  /*
   * Linear conversion.
   */
  adcConvert(&ADCD1, &adcgrpcfg1, samples1, ADC_GRP1_BUF_DEPTH);
  chThdSleepMilliseconds(1000);

  /*
   * Starts an ADC continuous conversion.
   */
//  adcStartConversion(&ADCD1, &adcgrpcfg2, samples2, ADC_GRP2_BUF_DEPTH);

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (TRUE) {
    if (palReadPad(PORT11, P11_BUTTON1)) {
//      adcStopConversion(&ADCD1);
    }
    chThdSleepMilliseconds(500);
  }
}