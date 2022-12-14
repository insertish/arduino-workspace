#ifndef LIGHTING_H
#define LIGHTING_H

#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

#ifndef NUM_LEDS
#define NUM_LEDS 100
#endif

#ifndef FASTLED_DATA_PIN
#define FASTLED_DATA_PIN 6
#endif

CRGB leds[NUM_LEDS];

void FastLED_configure()
{
    FastLED.addLeds<NEOPIXEL, FASTLED_DATA_PIN>(leds, NUM_LEDS);
}

void FastLED_show()
{
    noInterrupts();
    FastLED.show();
    interrupts();
}

#endif
