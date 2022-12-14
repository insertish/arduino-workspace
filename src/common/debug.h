#ifndef DEBUG_H
#define DEBUG_H

#define PIN_DEBUG_LED 2
#define PIN_INBUILT_LED 16

void set_debug_led(bool value)
{
    digitalWrite(PIN_DEBUG_LED, value ? LOW : HIGH);
}

void set_inbuilt_led(bool value)
{
    digitalWrite(PIN_INBUILT_LED, value ? LOW : HIGH);
}

void setup_debug()
{
    pinMode(PIN_DEBUG_LED, OUTPUT);
    pinMode(PIN_INBUILT_LED, OUTPUT);
    set_debug_led(false);
    set_inbuilt_led(false);
}

#endif