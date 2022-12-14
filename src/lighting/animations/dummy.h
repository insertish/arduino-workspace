#ifndef DUMMY_H
#define DUMMY_H
#include "./animation.h"
#include "../fastled.h"
#include "../colour.h"

void dummy_configure()
{
	for (int i = 1; i < NUM_LEDS; i++)
	{
		leds[i] = CRGB::Black;
	}

	if (NUM_LEDS)
		leds[0] = CRGB::White;
}

void dummy_run()
{
	FastLED_show();
	requestAnimationFrame();
}
#endif
