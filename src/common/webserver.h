#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ESP8266WebServer.h>

ESP8266WebServer webServer(80);

void setup_web_server()
{
    webServer.begin();
}

#endif
