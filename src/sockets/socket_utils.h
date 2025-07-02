#ifndef SOCKET_UTILS_H_
#define SOCKET_UTILS_H_

#include <winsock2.h>

// Створює сокет IPv4 TCP, повертає INVALID_SOCKET при помилці
SOCKET create_server_socket();

#endif  // SOCKET_UTILS_H_