#ifndef _LEDS_H__
#define _LEDS_H__

/*** includes ***/
#include <stdint.h>
#include <stdbool.h>

/*** function prototypes ***/
void LedsInit(uint16_t *);
void LedsTurnOnSingle(uint8_t led);
void LedsTurnOffSingle(uint8_t led);
bool IsLedTurn(uint8_t led);
void LedsTurnOffAll(void);
void LedsTurnOnAll(void);


#endif