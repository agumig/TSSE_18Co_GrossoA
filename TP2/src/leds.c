/**** includes ****/
#include "leds.h"

/**** definitions ****/
#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     0xFFFF
#define SINGLE_LED_OFF  0

/**** private function prototypes ****/
static uint16_t IndexToMask(uint8_t led);

/**** private variable ****/
static uint16_t *Direccion; // se almacena el mapeo en memoria del array de leds


/**** private functions ****/
static uint16_t IndexToMask(uint8_t led)
{
    return (FIRST_BIT << (led-INDEX_OFFSET));
}

/**** public functions ****/
void LedsInit(uint16_t * direccion)
{
    Direccion = direccion;
    LedsTurnOffAll();
}

void LedsTurnOnSingle(uint8_t led)
{
    *Direccion |= IndexToMask(led);
}

void LedsTurnOffSingle(uint8_t led)
{
    *Direccion &= ~IndexToMask(led);
}

bool IsLedTurn(uint8_t led)
{
    return ((*Direccion & IndexToMask(led)) != SINGLE_LED_OFF);
}

void LedsTurnOnAll(void)
{
    *Direccion = ALL_LEDS_ON;
}

void LedsTurnOffAll(void)
{
    *Direccion = ALL_LEDS_OFF;
}