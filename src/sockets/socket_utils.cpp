#include "socket_utils.h"

#include <iostream>

SOCKET create_server_socket() {
  // Server socket initialization
  SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (server_socket == INVALID_SOCKET) {
    std::cout << "Error initialization socket # " << WSAGetLastError() << std::endl;
    return INVALID_SOCKET;
  } else {
    std::cout << "Server socket initialization is OK" << std::endl;
  }

  return server_socket;
}