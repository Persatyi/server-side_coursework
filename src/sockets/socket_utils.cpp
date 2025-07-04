#include "socket_utils.h"

#include <iostream>

SOCKET create_server_socket() {
  // Server socket initialization
  SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == INVALID_SOCKET) {
    return INVALID_SOCKET;
  }

  return server_socket;
}

bool bind_server_socket(SOCKET socket, int port) {
  sockaddr_in serverInfo;
  // Initializing servInfo structure
  ZeroMemory(&serverInfo, sizeof(serverInfo));

  serverInfo.sin_family = AF_INET;     // AF_INET для інтернет підключень
  serverInfo.sin_addr = {INADDR_ANY};  // Прив'язка до всіх інтерфейсів
  serverInfo.sin_port = htons(port);   // Переводить int порт у мережевий формат

  return bind(socket, (sockaddr*)&serverInfo, sizeof(serverInfo));
}