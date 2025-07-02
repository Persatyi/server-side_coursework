#include <iostream>

#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  if (initialize_winsock()) {
    std::cout << "[TEST] WinSock init OK" << std::endl;
    cleanup_winsock();
  } else {
    std::cerr << "[TEST] WinSock init FAILED" << std::endl;
    return 1;
  }

  SOCKET sock = create_server_socket();
  if (sock == INVALID_SOCKET) {
    std::cerr << "[TEST] Failed: cannot create socket" << std::endl;
    cleanup_winsock();
    return 1;
  }
  std::cout << "[TEST] Passed: socket created" << std::endl;
  closesocket(sock);
  cleanup_winsock();

  return 0;
}