/*   CASOS DE USO
// Al inicializar la biblioteca todos los leds quedan apagados.
// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
// Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
// Prendo un led, consulto el estado y tiene que estar prendido.
// Apago un led, consulto el estado y tiene que estar apagado.
// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
// Con todos los leds prendidor, apagado todos los leds y verifico que se apagan.
// Revisar los valores limites de los argumentos.
// Revisar que pasa con valores erroneos en los argumento.
*/

#include "unity.h"
#include "leds.h"

static uint16_t puertoVirtual = 0xFF0F; // Inicializo en un valor cualquiera

void setUp(void)
{
    LedsInit(&puertoVirtual);   // inicializo la memoria
}

// Al inicializar la biblioteca todos los leds quedan apagados.
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t puertoVirtual = 0xFFFF; // 16 bits debido a que hay 16 leds

    LedsInit(&puertoVirtual);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual); // chequeo que sea igual a cero
}

// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
void test_prender_un_led(void)
{    
    LedsTurnOnSingle(2);
 
    TEST_ASSERT_EQUAL_HEX16(0x0002, puertoVirtual);
}


void test_prender_y_apagar_led(void)
{
    LedsTurnOnSingle(2);
    LedsTurnOffSingle(2);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual); // chequeo que sea igual a cero
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void)
{

    LedsTurnOnSingle(3);
    LedsTurnOnSingle(5);
    LedsTurnOffSingle(3);
    LedsTurnOffSingle(7);

    TEST_ASSERT_EQUAL_HEX16(0x0010, puertoVirtual); // chequeo
}

// Prendo un led, consulto el estado y tiene que estar prendido.
void test_prender_y_leer_un_led(void)
{
        LedsTurnOnSingle(3);
        TEST_ASSERT_EQUAL(true, IsLedTurn(3));
}

// Apago un led, consulto el estado y tiene que estar apagado.
void test_prender_apagar_y_leer_un_led(void)
{
        TEST_ASSERT_EQUAL(false, IsLedTurn(5));
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
void test_prender_todos_los_leds(void)
{
    LedsTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puertoVirtual); // chequeo
}

// Con todos los leds prendidor, apagado todos los leds y verifico que se apagan.
void test_apagar_todos_los_leds(void)
{
    LedsTurnOnAll();
    LedsTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual); // chequeo

}

// Revisar los valores limites de los argumentos.
void test_valores_limites_leds(void)
{
    LedsTurnOnSingle(16);
    LedsTurnOnSingle(1);

    TEST_ASSERT_EQUAL_HEX16(0x8001, puertoVirtual); // chequeo

}

// Revisar que pasa con valores erroneos en los argumento.
void test_valores_erroneos_leds(void)
{
    LedsTurnOnSingle(17);
    LedsTurnOnSingle(0);

   TEST_ASSERT_EQUAL_HEX16(0x00000, puertoVirtual); // chequeo

}