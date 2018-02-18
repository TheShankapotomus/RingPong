//
// Created by Josh Shank on 2/18/18.
//
#include "main.h"

#include <stdint.h>
#include <sys/socket.h>

#define RECV_ADDR "test.ring.com"
#define RECV_PORT 13469


int main(){

    uint16_t counter = 0;
    int udp_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if(udp_sock < 0){
        perror("Issue arose on socket creation! Exiting...");
        return 1;
    }

    return 0;
}

voltage