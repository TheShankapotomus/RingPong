//
// Created by Josh Shank on 2/18/18.
//

#include <unistd.h>
#include "hw_setup.h"

int GPIO_CALL(int pin, int state);

bool button_state(){

    return GPIO_CALL(BUTTON);
}

int battery_level(){


}

void activate_led(int LED, int state){

    GPIO_CALL(LED, state);
}

//25% duty cycle w/ 1s pulse width @ 2Hz
void low_power_indicator(int state){

    //add loop here?
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

void GPIO_CALL(int, int){


}