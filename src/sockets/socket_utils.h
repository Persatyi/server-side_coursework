#ifndef SOCKET_UTILS_H_
#define SOCKET_UTILS_H_

#include <winsock2.h>

// Створює сокет IPv4 TCP, повертає INVALID_SOCKET при помилці
SOCKET create_server_socket();

// Прив'язка сокета до порту
bool bind_server_socket(SOCKET socket, int port);

// Починаємо слухати порт
bool start_listening(SOCKET socket);

#endif  // SOCKET_UTILS_H_