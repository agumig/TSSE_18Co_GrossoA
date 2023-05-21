/****** includes ******/
#include "hw_pressure.h"
#include "hw_pressure_port.h"

/****** macros and definitions ******/
#define TAG  "HW_PRESSURE"

typedef struct pressure_s
{
    uint8_t gpio_Pin;       // GPIO number (ADC channel)
    bool_t alocated;
}pressure_t;


static pressure_t PressureDevices[CANT_PRESSURE_DEVICES] = {0};

/****** public functions ******/

pressure_p HW_Pressure_Init(uint8_t ADC_channel)
{
    uint8_t i = 0;
    pressure_p returnValue = NULL;

    for ( i = 0; i < CANT_PRESSURE_DEVICES; i++)
    {
        if(false == PressureDevices[i].alocated)
        {
            returnValue = &(PressureDevices[i]);
            PressureDevices[i].alocated = true;
            PressureDevices[i].gpio_Pin = ADC_channel;
            //printf("Se asignó el objeto %d: %p \n", i, (void *)returnValue);
            break;
        }
    }

    if(NULL != returnValue)
    {
        HW_Pressure_init_port(returnValue);
    }

    return returnValue;        
}

bool_t HW_Pressure_Free(pressure_p *pressureDevice)
{
    int i = 0;
    bool_t returnValue = false;

    for ( i = 0; i < CANT_PRESSURE_DEVICES; i++)
    {
        if(*pressureDevice == &(PressureDevices[i]))
        {
            PressureDevices[i].alocated = false;    // desasigno el objeto
            *pressureDevice = NULL;
            returnValue = true;

            break;
        }
    }

    return returnValue;
}
double HW_Pressure_read_pascal(pressure_p pressureDevice)
{
    uint32_t ADCVoltage;
    double pressure;

    ADCVoltage = HW_Pressure_read_port(pressureDevice);

    if(VOLTAGE_RANGE_MIN >= ADCVoltage)
    {
        pressure = PRESSURE_RANGE_MIN;
    }        
    else
    {
        if(VOLTAGE_RANGE_MAX <= ADCVoltage)
        {
            pressure = PRESSURE_RANGE_MAX;
        }
        else
        {
            pressure = ADCVoltage * PRESSURE_CONSTANT_MV_PA;
        }
    }
    
    return (pressure);
}