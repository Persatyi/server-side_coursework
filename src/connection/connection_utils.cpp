#include "connection_utils.h"

#include <ws2tcpip.h>  // inet_ntop

#include <iostream>

SOCKET accept_client(SOCKET server_socket) {
  sockaddr_in clientInfo;
  ZeroMemory(&clientInfo, sizeof(clientInfo));  // Initializing clientInfo structure

  int clientSize = sizeof(clientInfo);

  SOCKET client_socket =
      accept(server_socket, reinterpret_cast<sockaddr*>(&clientInfo), &clientSize);
  if (client_socket == INVALID_SOCKET) {
    std::cerr << "accept() failed. Error: " << WSAGetLastError() << std::endl;
    return INVALID_SOCKET;
  } else {
    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(clientInfo.sin_addr), clientIP, INET_ADDRSTRLEN);

    std::cout << "Client connected from IP: " << clientIP
              << ", port: " << ntohs(clientInfo.sin_port) << std::endl;
  }

  return client_socket;
}