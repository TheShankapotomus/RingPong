#ifndef RINGPONG_UDP_SERVER_H
#define RINGPONG_UDP_SERVER_H

#define BIND_PORT 13469
#define TARGET_ADDR "test.ring.com"
#define TARGET_PORT 13469

void setup_socket();
void send_data(uint16_t);
int recv_data();

#endif //RINGPONG_UDP_SERVER_H
