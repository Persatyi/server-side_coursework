#include <winsock2.h>

#include <iostream>
#include <string>

#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  const std::string kServer_IP = "127.0.0.1";  // Enter local Server IP address
  constexpr int kPortNum = 8080;               // Enter Open working server port

  if (initialize_winsock()) {
    std::cout << "[TEST] WinSock init OK" << std::endl;
  } else {
    std::cerr << "[TEST] WinSock init FAILED" << std::endl;
    return 1;
  }

  SOCKET sock = create_server_socket();
  if (sock == INVALID_SOCKET) {
    std::cout << "Socket: " << static_cast<uint64_t>(sock) << std::endl;
    std::cerr << "[TEST] Failed: cannot create socket" << std::endl;
    cleanup_winsock();
    return 1;
  }
  std::cout << "[TEST] Passed: socket created" << std::endl;

  bool is_bool_bind_success = bind_server_socket(sock, kPortNum);  // будь-який не-зайнятий порт
  if (!is_bool_bind_success) {
    closesocket(sock);
    cleanup_winsock();
    std::cerr << "[TEST] Failed: Socket binding. Error #" << WSAGetLastError() << std::endl;
  }
  std::cout << "[TEST] Passed: socket bound successfully" << std::endl;

  if (!start_listening(sock)) {
    std::cerr << "[TEST] Failed: listen failed. Error #" << WSAGetLastError() << std::endl;
    closesocket(sock);
    cleanup_winsock();
    return 1;
  }
  std::cout << "[TEST] Passed: socket is listening" << std::endl;

  closesocket(sock);
  cleanup_winsock();

  return 0;
}