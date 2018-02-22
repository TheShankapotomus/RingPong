#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hw_setup.h"
#include "udp_server.h"

/*
 * This main function is meant to be used for testing the
 * reference system through simple state emulations. The variables
 * that are able to be changed are the button state and voltage read
 * in by the ADC. This function runs through minimal testing and is expected
 * to be stopped abruptly. If this is to be implemented on an embedded
 * platform, a continuous loop would most likely be thrown above the first
 * while loop and would encompass the rest of the main function.
 */
int main(int argc, char *argv[]){

    if(argc < 3 || argc > 3){
        printf("\nusage: ./ring-pong [button state] [current voltage]\n");
        printf("button state is either 1 or 0, current voltage is 0.0 - 5.0 volts\n");
        printf("\nexample usage: ./ring-pong 1 3.5\n");
        exit(0);
    }else{

        set_button_state(atoi(argv[1]));
        set_battery_level(atof(argv[2]));
    }

    int tmp;
    uint16_t count = 0;

    //***EXTERIOR WHILE LOOP HERE***

    while(battery_status() < MIN_VOLTAGE)
        low_power_indicator(HIGH);

    low_power_indicator(LOW);

    if(button_status() == HIGH && battery_status() >= MIN_VOLTAGE){

        activate_led(WHITE_LED, HIGH);
        setup_socket();

        while(button_status() == HIGH && battery_status() >= MIN_VOLTAGE){

            send_data(count);     //send packet to server
            usleep(500000);       //wait 500ms for response
            tmp = recv_data();

            if(tmp == count) count++;
            usleep(500000);
        }

        activate_led(WHITE_LED, LOW);
        cleanup_socket();
        count = 0;
    }

    return 0;
}