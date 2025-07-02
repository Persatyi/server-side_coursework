#include <iostream>

#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  // WinSock initialization
  if (!initialize_winsock()) {
    return 1;
  }

  // Server socket initialization
  SOCKET server_socket = create_server_socket();
  if (server_socket == INVALID_SOCKET) {
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Server socket initialization is OK" << std::endl;
  }

  return 0;
}