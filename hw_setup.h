#ifndef RINGPONG_HW_SETUP_H
#define RINGPONG_HW_SETUP_H

#include <inttypes.h>
#include <stdbool.h>

#define LOW 0            // low state macro
#define HIGH 1           // high state macro
#define MIN_VOLTAGE 3500 // minimum voltage for system functionality measured in millivolts
#define BUTTON 2         // button GPIO pin
#define WHITE_LED 3      // white led GPIO pin
#define RED_LED 4        // red led GPIO pin

uint16_t battery_level();
bool button_state();
void activate_led(int, int);
void low_power_indicator(int);

#endif //RINGPONG_HW_SETUP_H
