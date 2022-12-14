#ifndef ESP8266_H
#define ESP8266_H

#ifndef USE_OTA_WEB_ROUTE
#define USE_OTA_WEB_ROUTE 1
#endif

#include "./wifi.h"
#include "./debug.h"
#include "./ota.h"
#include "./webserver.h"

void setup_esp8266()
{
    setup_debug();
    connect_wifi();
    setup_ota();
    setup_web_server();
}

void yieldDelay(int time)
{
    webServer.handleClient();
    delay(time);
}

#endif
