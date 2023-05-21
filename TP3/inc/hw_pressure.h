#ifndef __HW_PRESSURE_H_
#define __HW_PRESSURE_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/********* macros and definitions *********/

typedef struct pressure_s *pressure_p;

typedef bool bool_t;

#define CANT_PRESSURE_DEVICES 4

#define VOLTAGE_RANGE_MIN   500     // [mV]
#define VOLTAGE_RANGE_MAX   4500    // [mV]
#define PRESSURE_RANGE_MIN  0       // [Pa]
#define PRESSURE_RANGE_MAX  1600000 // [Pa]

#define PRESSURE_CONSTANT_V_MEGPA   0.355555556     // [MPa/V]  Constante para convertis vot a mega pascales
#define PRESSURE_CONSTANT_MV_PA     355.555556      // [Pa/mV]  Constante para convertis milivolt a pascales

/********* function prototypes *********/

/**
 * @brief Init presure device instance
 * @param pressure_t instance
 */

pressure_p HW_Pressure_Init(uint8_t ADC_channel);

/**
 * @brief Read pressure value
 * @param pressure_t device to read
 * @return double [pa]
 */
double HW_Pressure_read_pascal(pressure_p pressureDevice);

/**
 * @brief Delete an instance
 * 
 * @param pressureDevice 
 * @return bool_t true if it's deleted correctly, false if not
 */
bool_t HW_Pressure_Free(pressure_p *pressureDevice);

#endif