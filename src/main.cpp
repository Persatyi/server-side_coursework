#include <iostream>

#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  const int kPortNum = 0;  // Enter Open working server port

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
  if (!bind_server_socket(server_socket, kPortNum)) {
    std::cerr << "Error Socket binding. Error #" << WSAGetLastError() << std::endl;
    closesocket(server_socket);
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Binding socket to server info is OK" << std::endl;
  }

  return 0;
}