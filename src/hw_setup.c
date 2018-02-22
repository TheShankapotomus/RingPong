#include <stdio.h>
#include <unistd.h>
#include "hw_setup.h"

int battery_level = 0;
int button_state = LOW;
int white_led_state = LOW;
int red_led_state = LOW;

void GPIO_CALL(int, int);

int button_status(){

    return button_state;
}

int battery_status(){

    return battery_level;
}

//wrapper for GPIO_CALL to set button_state
void set_button_state(int state){

    GPIO_CALL(BUTTON, state);
}

//12-bit ADC referencing the system's 3.5V
void set_battery_level(float volts){

    //(4095/3500mV) = ( 1.17 * volts * 1000)) = ?
    battery_level = (int)(1.17 * volts * 1000) + 1;
    printf("\nBattery level is now %d mV\n", (int)(volts*1000));
}

void activate_led(int LED, int state){

    GPIO_CALL(LED, state);
}

//25% duty cycle w/ 1s pulse width @ 2Hz
void low_power_indicator(int state){

    if(state == HIGH){

        for(int i = 0; i < 2; i++) {

            GPIO_CALL(RED_LED, HIGH);
            usleep(250000);             //sleep for 250 ms
            GPIO_CALL(RED_LED, LOW);
            usleep(250000);
        }
    }else if(state == LOW)
        GPIO_CALL(RED_LED, LOW);
}

//GPIO interface to handle state switching
void GPIO_CALL(int pin, int state) {

    if (state > HIGH || state < LOW) {
        perror("\nInvalid digital state passed.\n");

    }else {

        char *update = (state == HIGH) ? "ON" : "OFF";
        if (pin == BUTTON) {

            button_state = state;
            printf("\nPush button is now %s\n", update);
        } else if (pin == WHITE_LED) {

            white_led_state = state;
            printf("\nWhite LED is now %s\n", update);
        } else if (pin == RED_LED) {

            red_led_state = state;
            printf("\nRed LED is now %s\n", update);
        }
    }
}