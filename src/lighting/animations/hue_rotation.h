#ifndef HUE_ROTATION_H
#define HUE_ROTATION_H
#include "./animation.h"
#include "../fastled.h"
#include "../colour.h"

float ledHue[NUM_LEDS];

float hue = 0;
const float saturation = 0.8, lightness = 0.1;
const float hueStepValue = 0.05f;
const float hueFlowValue = 0.01f;
const float MAX_HUE = 1.0f;
const int LENGTH = 60;

void hue_rotation_configure()
{
	float currentHue = 0;
	for (int i = 0; i < NUM_LEDS; i++)
	{
		ledHue[i] = currentHue;
		currentHue += hueStepValue;
		if (currentHue >= MAX_HUE)
			currentHue = 0;
	}
}

void hue_rotation_run()
{
	while (true)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			uint8_t r, g, b;
			HslToRgb(ledHue[i], saturation, lightness, r, g, b);
			leds[i] = CRGB(r, g, b);
		}

		for (int i = 0; i < NUM_LEDS; i++)
		{
			ledHue[i] += hueFlowValue;
			if (ledHue[i] >= MAX_HUE)
				ledHue[i] = 0;
		}

		FastLED_show();
		if (requestAnimationFrame())
			break;
	}
}
#endif
