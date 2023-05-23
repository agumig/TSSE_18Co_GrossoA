# TSSE_18Co_GrossoA
Repositorio de alumno  Agustín Grosso de Testing de Software en Sistemas Embebidos

## Trabajo práctico 2. TDD.
***2023-05-15***
Testing de un controlador de leds

*FUNCIONALIDADES*
- Después de la inicialización todos los LEDs deben quedar apagados.
- Se puede prender un LED individual.
- Se puede apagar un LED individual.
- Se pueden prender y apagar múltiples LED’s.
- Se pueden prender todos los LEDs de una vez.
- Se pueden apagar todos los LEDs de una vez.
- Se puede consultar el estado de un LED.

## Trabajo práctico 3. Testing unitario.
***2023-05-22***
Testing de un sensor de presión analógico leído a través de un ADC.

- El software debe poder generar una instancia con memoria estática para cada sensor de presión.
- El software debe poder eliminar una instancia inicializada.
- El software debe inicializar una cantidad ya definida de dispositivos.
- El software debe entregar los valores convertidos a PASCAL según la ecuación de conversión 1mv = 355.555556 pa
- El software debe entregar valor 0 para lecturas menores a el límite inferior (500 mV) y saturar para lecturas mayores a 4500 mV.