#include <winsock2.h>

#include <iostream>
#include <string>

#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  const std::string kServer_IP = "127.0.0.1";  // Enter local Server IP address
  constexpr int kPortNum = 8080;               // Enter Open working server port

  // WinSock initialization
  if (!initialize_winsock()) {
    return 1;
  }

  // Server socket initialization
  SOCKET server_socket = create_server_socket();
  if (server_socket == INVALID_SOCKET) {
    std::cout << "Error initialization socket # " << WSAGetLastError() << std::endl;
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Server socket initialization is OK" << std::endl;
  }

  // Server socket binding
  if (!bind_server_socket(server_socket, kPortNum, kServer_IP)) {
    std::cerr << "Error Socket binding. Error #" << WSAGetLastError() << std::endl;
    closesocket(server_socket);
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Binding socket to server info is OK" << std::endl;
    std::cout << "Binding to IP: " << kServer_IP << ", port: " << kPortNum << std::endl;
  }

  // Starting to listen to any Clients
  if (!start_listening(server_socket)) {
    std::cerr << "Listen failed. Error: " << WSAGetLastError() << std::endl;
    closesocket(server_socket);
    cleanup_winsock();
    return 1;
  }
  std::cout << "Server is listening..." << std::endl;

  closesocket(server_socket);
  cleanup_winsock();

  return 0;
}