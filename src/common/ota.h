#ifndef OTA_H
#define OTA_H

#include "./debug.h"
#ifdef USE_OTA_WEB_ROUTE
#include "./webserver.h"
#endif

#include <ArduinoOTA.h>

bool __ota_status = false;

void handle_ota()
{
  ArduinoOTA.handle();
}

void setup_ota()
{
  ArduinoOTA.onStart([]()
                     { set_debug_led(true); });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                        {
    set_debug_led(__ota_status);
    __ota_status ^= true; });

  ArduinoOTA.onEnd([]()
                   { set_debug_led(false); });

  ArduinoOTA.begin();

#ifdef USE_OTA_WEB_ROUTE
  webServer.on("/ota", HTTPMethod::HTTP_GET, []()
               { webServer.send(200, "text/plain", "Switching to OTA update mode now.");
                   while (true) {
                     handle_ota();
                     delay(1);
                   } });
#endif
}

#endif
