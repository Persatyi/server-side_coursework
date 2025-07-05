#ifndef SOCKET_UTILS_H_
#define SOCKET_UTILS_H_

#include <winsock2.h>

#include <string>

// Створює сокет IPv4 TCP, повертає INVALID_SOCKET при помилці
SOCKET create_server_socket();

// Прив'язка сокета до порту
bool bind_server_socket(SOCKET socket, int port, const std::string& ipAddress = "");

// Починаємо слухати порт
bool start_listening(SOCKET socket);

#endif  // SOCKET_UTILS_H_