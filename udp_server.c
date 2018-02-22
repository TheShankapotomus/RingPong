#include <dnet.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <netdb.h>
#include "udp_server.h"

int udp_sock;
struct sockaddr_in host, client;

void safe_close(const char*);

void setup_socket(){

    int bind_state;
    struct hostent *he;
    udp_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if(udp_sock < 0)
        safe_close("Error caught on socket creation.");

    memset((char *)&host, 0, sizeof(host));
    host.sin_family = AF_INET;
    host.sin_addr.s_addr = htons(INADDR_ANY);
    host.sin_port = htons(BIND_PORT);

    memset((char *)&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(TARGET_PORT);
    he = gethostbyname(TARGET_ADDR);
    memcpy((void *)&client.sin_addr, he->h_addr_list[0], he->h_length);

    bind_state = bind(udp_sock, (struct sockaddr *)&host, sizeof(host));

    if(bind_state < 0)
        safe_close("Error caught attempting to bind on localhost to port.");
}

void send_data(uint16_t payload){

    payload = htons(payload);
    int state = sendto(udp_sock, &payload, sizeof(payload), 0, (struct sockaddr *)&client, sizeof(client));

    if(state < 0)
        safe_close("Error caught on sendto() for UDP socket.");
}

int recv_data(){

     int payload = -1;
     socklen_t caddr_len = sizeof(client);
     int length = recvfrom(udp_sock, &payload, sizeof(uint16_t), 0, (struct sockaddr*)&client, &caddr_len);

     if(length > 0){
        return ntohs((short)payload);

     }else{
        safe_close("No payload received.");
        return payload;
     }
}

void safe_close(const char *message){

    perror(message);
    close(udp_sock);
}

int main(){

  setup_socket();
  send_data(2048);
  printf("%" PRIu16 "\n", (short)recv_data());
  send_data(4096);
  printf("%" PRIu16 "\n", (short)recv_data());
}
