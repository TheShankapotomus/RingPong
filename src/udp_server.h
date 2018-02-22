#ifndef RINGPONG_UDP_SERVER_H
#define RINGPONG_UDP_SERVER_H

#define BIND_PORT 13469
#define TARGET_ADDR "test.ring.com"
#define TARGET_PORT 13469

#include <inttypes.h>

/**
 * Setup all global variables to be used for send and receive operations.
 * udp_sock, host, and client are all populated with the default ip/port data.
 * client is setup to use a domain name by default; udp_sock is bound to the host
 */
void setup_socket();

/**
 * Convert a 16 bit integer to network byte-order, then send to client
 */
void send_data(uint16_t);

/**
 * Attempt to receive a 16 bit integer then convert to host byte-order.
 * An integer is returned rather than a uint16_t since a poor payload
 * could come across; if proper, it is cast to a short before being returned.
 *
 * @return 16 bit integer from client or -1 if no payload is received
 */
int recv_data();

/**
 * Simply run a close() on udp_sock
 */
void cleanup_socket();

#endif //RINGPONG_UDP_SERVER_H
