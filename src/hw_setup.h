#ifndef RINGPONG_HW_SETUP_H
#define RINGPONG_HW_SETUP_H

#define LOW 0            // low state macro
#define HIGH 1           // high state macro
#define MIN_VOLTAGE 4095 // minimum level for system functionality from 12-bit ADC
#define BUTTON 2         // button GPIO pin
#define WHITE_LED 3      // white led GPIO pin
#define RED_LED 4        // red led GPIO pin


/**
 * Simple getter for button_state
 * @return current button_state
 */
int button_status();

/**
 * Simple getter for battery_level
 * @return battery level in mV
 */
int battery_status();

/**
 * Simple wrapper for GPIO_CALL to set button_state
 */
void set_button_state(int);

/**
 * Takes a ADC read voltage and calculates
 * the current level in reference to mV.
 * ADC is assumed to be 12-bit (4095/3500)*V*1000
 */
void set_battery_level(float);

/**
 * Wrapper for GPIO_CALL to set LED state
 */
void activate_led(int, int);

/**
 * Activates low power indication by flashing a red LED
 * with a 25% duty cycle at 2Hz over a 1s period.
 */
void low_power_indicator(int);

#endif //RINGPONG_HW_SETUP_H
