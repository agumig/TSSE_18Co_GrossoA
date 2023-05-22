/********* includes *********/
#include "hw_pressure_port.h"
#include "hw_pressure.h"

/********* macros and definitions *********/
#define TAG  "HW_PRESSURE_PORT"

uint32_t valorTesting = 0;  // variable que guarda las cuentas del ADC

/********* private function prototypes *********/

/*!
 * @brief Init ADC1
 * @param pressure_t device to initialize over ADC1
 * @return none
 */
static void ADC1_init_port(pressure_p pressure);
/*!
 * @brief Init ADC2
 * @param pressure_t device to initialize over ADC2
 * @return none
 */
static void ADC2_init_port(pressure_p pressure);
/*!
 * @brief Convert the ADC read in a voltage value
 * @param pressure_t device to read
 * @return uint32_t voltage read
 */
static uint32_t ADC1_readVoltage_port(pressure_p pressure);
/*!
 * @brief Convert the ADC read in a voltage value
 * @param pressure_t device to read
 * @return uint32_t voltage read
 */
static uint32_t ADC2_readVoltage_port(pressure_p pressure);
/*!
 * @brief Read ADC1 counts
 * @param pressure_t device to read
 * * @return uint32_t counts read
 */
static uint32_t ADC1_read_port(uint8_t channel);
/*!
 * @brief Read ADC2 counts
 * @param pressure_t device to read
 * @return uint32_t counts read
 */
static uint32_t ADC2_read_port(uint8_t channel);


/********* public functions *********/
void HW_Pressure_init_port(pressure_p pressureDevice)
{
    ADC2_init_port(pressureDevice);   // Se usa solamente el ADC2 en el desarrollo   

}

uint32_t HW_Pressure_read_port(pressure_p pressureDevice)
{
    return ADC2_readVoltage_port(pressureDevice);
}

/********* private functions *********/

static void ADC1_init_port(pressure_p pressureDevice)
{

}


static void ADC2_init_port(pressure_p pressureDevice)
{

}


static uint32_t ADC1_readVoltage_port(pressure_p pressureDevice)
{
    uint32_t adc_reading;

    return adc_reading;
}


static uint32_t ADC2_readVoltage_port(pressure_p pressureDevice)
{
    uint32_t adc_reading;

    adc_reading = valorTesting;
    
    return adc_reading;
}


static uint32_t ADC1_read_port(uint8_t channel)
{
    uint32_t value = 0;

    return (value);
}

static uint32_t ADC2_read_port(uint8_t channel)
{
    uint32_t value = 0, realSamples = 0;

    return (value/realSamples);
}