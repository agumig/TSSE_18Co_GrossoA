#ifndef __HW_PRESSURE_PORT_H_
#define __HW_PRESSURE_PORT_H_

/********* includes *********/
//#include "main.h"
#include "hw_pressure.h"
//#include "driver/adc.h"
//#include "esp_adc_cal.h"

/********* macros and definitions *********/
/** Características del ADC **/

#define ADC_RESOLUTION      ADC_WIDTH_BIT_12    // Resolucion de los 18 canales de ADC
#define ADC_ATTEN           ADC_ATTEN_DB_11     // Full-scale voltage 3.13V
#define DEFAULT_VREF        CONFIG_DEFAULT_VREF // Por diseño la referencia de tensión del ADC es 1100 mV
#define N_SAMPLES           CONFIG_ADC_SAMPLES  // 64 inicialmente

/********* function prototypes *********/
/*!
 * @brief   Hardware ADC Init - Main function
 * @param   pressure_t device to read
 * @return  bool true if it was OK, flase if not
 */
void HW_Pressure_init_port(pressure_p pressure);

/*!
 * @brief   Read ADC voltage - Main function
 * @param   pressure_t device to read
 * @return  uint32_t voltage value
 */
uint32_t HW_Pressure_read_port(pressure_p pressure);

#endif