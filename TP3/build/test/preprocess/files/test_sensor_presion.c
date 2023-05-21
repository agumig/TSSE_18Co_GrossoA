#include "inc/hw_pressure_port.h"
#include "inc/hw_pressure.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








extern uint32_t valorTesting;



pressure_p sensor[(4 + 2)] = {

                                         ((void *)0)

                                             };















void instanciar_primer_dispositivo()

{

    sensor[0] = HW_Pressure_Init(2);

    do {if ((((sensor[0])) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(31))));}} while(0);

}



void desinstanciar_primer_dispositivo()

{

    bool_t sensorDeleted = 

                          0

                               ;



    sensorDeleted = HW_Pressure_Free(&sensor[0]);

    do {if ((sensorDeleted)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    do {if ((((sensor[0])) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(40))));}} while(0);

}







void test_inicializacion(void)

{

    instanciar_primer_dispositivo();

}





void test_eliminar_instancia(void)

{

    desinstanciar_primer_dispositivo();

}





void test_inicializacion_de_demasiados_sensores(void)

{

    int i = 0;



    for(i = 0; i< (4 + 2); i++)

        sensor[i] = HW_Pressure_Init(2);



    for(i = 0; i < 4; i++)

        do {if ((((sensor[i])) != 

       ((void *)0)

       )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(65))));}} while(0);



    for( i = 4; i < (4 + 2); i++)

        do {if ((((sensor[i])) == 

       ((void *)0)

       )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(68))));}} while(0);



    for(i = 0; i < 4; i++)

    {

        HW_Pressure_Free(&sensor[i]);

        do {if ((((sensor[i])) == 

       ((void *)0)

       )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(73))));}} while(0);

    }

}







void test_obtener_valores_en_pascal()

{

    double pressureValue = 0;



    instanciar_primer_dispositivo();



    valorTesting = 1350;

    pressureValue = HW_Pressure_read_pascal(sensor[0]);

    UnityAssertEqualNumber((UNITY_INT)(((int64_t)(valorTesting * 355.555556))), (UNITY_INT)(((int64_t)pressureValue)), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT64);



    desinstanciar_primer_dispositivo();



}







void test_obtener_valores_limites_en_pascal()

{

    double pressureValue = 0;



    instanciar_primer_dispositivo();



    valorTesting = 250;

    pressureValue = HW_Pressure_read_pascal(sensor[0]);

    UnityAssertEqualNumber((UNITY_INT)(((int64_t) 0)), (UNITY_INT)(((int64_t)pressureValue)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT64);



    valorTesting = 70000;

    pressureValue = HW_Pressure_read_pascal(sensor[0]);

    UnityAssertEqualNumber((UNITY_INT)(((int64_t) 1600000)), (UNITY_INT)(((int64_t)pressureValue)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT64);



    desinstanciar_primer_dispositivo();



}
