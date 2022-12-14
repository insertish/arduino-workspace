#ifndef WIFI_H
#define WIFI_H

#include "./debug.h"
#include "../../config.h"

#include <ESP8266WiFi.h>

void connect_wifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    bool indicator = false;
    while (WiFi.status() != WL_CONNECTED)
    {
        set_inbuilt_led(indicator);
        indicator ^= true;
        delay(500);
    }

    set_inbuilt_led(false);
}

#endif
