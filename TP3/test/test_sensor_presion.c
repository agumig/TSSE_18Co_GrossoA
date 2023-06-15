/****
 * DEVICE DRIVER - sensor de presión
 * CASOS DE USO
 * 1. El software debe poder generar una instancia con memoria estática para cada sensor de presión.
 * 2. El software debe poder eliminar una instancia inicializada.
 * 3. El software debe inicializar la cantidad ya definida de dispositivos.
 * 4. El software debe entregar los valores convertidos a PASCAL según la ecuación de conversión 1mv = 355.555556 pa
 * 5. El software debe entregar valor 0 para lecturas menores a el límite inferior (500 mV) y saturar para lecturas mayores a 4500 mV
*/

#include "unity.h"
#include "hw_pressure.h"
#include "mock_hw_pressure_port.h"

#define DEMASIADOS_SENSORES (CANT_PRESSURE_DEVICES + 2)
#define PIN_CANAL_ADC 2 // Canal usado para inicializar

pressure_p sensor[DEMASIADOS_SENSORES] = {NULL};    // sensores a instanciar

static void instanciar_primer_dispositivo();
static void desinstanciar_primer_dispositivo();

/*
void test_siempre_falla(void)
{
    TEST_FAIL_MESSAGE("Empezamos...");
}
*/

static void instanciar_primer_dispositivo()
{
    sensor[0] = HW_Pressure_Init(PIN_CANAL_ADC);
    TEST_ASSERT_NOT_NULL(sensor[0]); 
}

static void desinstanciar_primer_dispositivo()
{
    bool_t sensorDeleted = false;

    sensorDeleted = HW_Pressure_Free(&sensor[0]);
    TEST_ASSERT_TRUE(sensorDeleted); 
    TEST_ASSERT_NULL(sensor[0]); 
}

// 1. El software debe poder generar una instancia con memoria estática para cada sensor de presión.

void test_inicializacion(void)
{
    instanciar_primer_dispositivo();
}

// 2. El software debe poder eliminar una instancia inicializada
void test_eliminar_instancia(void)
{
    desinstanciar_primer_dispositivo();
}

// 3. El software debe inicializar la cantidad ya definida de dispositivos.
void test_inicializacion_de_demasiados_sensores(void)
{
    int i = 0;

    for(i = 0; i< DEMASIADOS_SENSORES; i++)
        sensor[i] = HW_Pressure_Init(PIN_CANAL_ADC);
        
    for(i = 0; i < CANT_PRESSURE_DEVICES; i++)
        TEST_ASSERT_NOT_NULL(sensor[i]);

    for( i = CANT_PRESSURE_DEVICES; i < DEMASIADOS_SENSORES; i++)
        TEST_ASSERT_NULL(sensor[i]);

    for(i = 0; i < CANT_PRESSURE_DEVICES; i++)
    {
        HW_Pressure_Free(&sensor[i]);
        TEST_ASSERT_NULL(sensor[i]);   
    }
}

// 4. El software debe entregar los valores convertidos a PASCAL según la ecuación de conversión 1mv = 355.555556 pa

void test_obtener_valores_en_pascal()
{
    double pressureValue = 0;

    instanciar_primer_dispositivo();

    HW_Pressure_read_port_fake.return_val = 1350;    // el adc leerá 1350 mV
    pressureValue = HW_Pressure_read_pascal(sensor[0]);
    TEST_ASSERT_EQUAL_INT64 ((int64_t)(1350 * PRESSURE_CONSTANT_MV_PA), (int64_t)pressureValue);
    
    desinstanciar_primer_dispositivo();

}

// 5. El software debe entregar valor 0 para lecturas menores a el límite inferior (500 mV) y saturar para lecturas mayores a 4500 mV

void test_obtener_valores_limites_en_pascal()
{
    double pressureValue = 0;

    instanciar_primer_dispositivo();

    HW_Pressure_read_port_fake.return_val = 250; // el adc leerá 250 mV (debajo del límite inferior)
    pressureValue = HW_Pressure_read_pascal(sensor[0]);
    TEST_ASSERT_EQUAL_INT64 ((int64_t) PRESSURE_RANGE_MIN, (int64_t)pressureValue);
    
    HW_Pressure_read_port_fake.return_val = 70000; // el adc leerá 70000 mV (por encima del límite superior)
    pressureValue = HW_Pressure_read_pascal(sensor[0]);
    TEST_ASSERT_EQUAL_INT64 ((int64_t) PRESSURE_RANGE_MAX, (int64_t)pressureValue);

    desinstanciar_primer_dispositivo();

}