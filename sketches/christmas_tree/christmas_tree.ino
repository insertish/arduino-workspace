#define NUM_LEDS 119
#define FASTLED_DATA_PIN 5

#include "src/common/esp8266.h"
#include "src/lighting/animations/hue_rotation.h"

void setup()
{
  webServer.on("/", HTTPMethod::HTTP_GET, []()
               { webServer.send(200, "text/plain", "Hello, I am a Christmas tree!"); });

  setup_esp8266();
  FastLED_configure();
  hue_rotation_configure();
}

void loop()
{
  hue_rotation_run();
}

bool requestAnimationFrame()
{
  yieldDelay(16);
  return false;
}
