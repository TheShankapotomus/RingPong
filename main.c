#include <stdint.h>
#include "hw_setup.h"
#include "udp_server.h"


int main(){

    uint16_t counter = 0;

    while(1){
        if(button_state() == 1 && battery_level() >= MIN_VOLTAGE){

            activate_led(WHITE_LED, HIGH);

            //light white led, activate network fucntionality
        }else if(battery_level() < MIN_VOLTAGE){

            low_power_indicator(HIGH);
        }
    }
}