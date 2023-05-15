#ifndef _LEDS_H__
#define _LEDS_H__

/*** includes ***/
#include <stdint.h>
#include <stdbool.h>


/**
 * @brief   Función de inicialización del array de leds
 * @details Inicia los led como apagados
 */
void LedsInit(uint16_t *);

/**
 * @brief Encendido de un led
 * 
 * @param led número de led a encender
 */
void LedsTurnOnSingle(uint8_t led);

/**
 * @brief Apagado de un led
 * 
 * @param led número de led a apagara
 */
void LedsTurnOffSingle(uint8_t led);

/**
 * @brief Adquisición del estado de un led
 * 
 * @param led número de led a consultar
 * @return true si está encendido
 * @return false si está apagado
 */
bool IsLedTurn(uint8_t led);

/**
 * @brief Apagado de todos los leds
 * 
 */
void LedsTurnOffAll(void);

/**
 * @brief Encendido de todos los leds
 * 
 */
void LedsTurnOnAll(void);


#endif