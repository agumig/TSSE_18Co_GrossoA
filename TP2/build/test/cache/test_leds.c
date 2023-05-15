#include "inc/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t puertoVirtual = 0xFF0F;



void setUp(void)

{

    LedsInit(&puertoVirtual);

}

void test_todos_los_leds_inician_apagados(void)

{

    uint16_t puertoVirtual = 0xFFFF;



    LedsInit(&puertoVirtual);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_HEX16);



}





void test_prender_un_led(void)

{

    LedsTurnOnSingle(2);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_led(void)

{

    LedsTurnOnSingle(2);

    LedsTurnOffSingle(2);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void)

{



    LedsTurnOnSingle(3);

    LedsTurnOnSingle(5);

    LedsTurnOffSingle(3);

    LedsTurnOffSingle(7);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_leer_un_led(void)

{

        LedsTurnOnSingle(3);

        UnityAssertEqualNumber((UNITY_INT)((

       1

       )), (UNITY_INT)((IsLedTurn(3))), (

       ((void *)0)

       ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_apagar_y_leer_un_led(void)

{

        LedsTurnOnSingle(5);

        LedsTurnOffSingle(5);



        UnityAssertEqualNumber((UNITY_INT)((

       0

       )), (UNITY_INT)((IsLedTurn(5))), (

       ((void *)0)

       ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_todos_los_leds(void)

{

    LedsTurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_leds(void)

{

    LedsTurnOnAll();

    LedsTurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_HEX16);



}





void test_valores_limites_leds(void)

{

    LedsTurnOnSingle(16);

    LedsTurnOnSingle(1);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_HEX16);



}





void test_valores_erroneos_leds(void)

{

    LedsTurnOnSingle(17);

    LedsTurnOnSingle(0);



   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00000)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (

  ((void *)0)

  ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_HEX16);



}
