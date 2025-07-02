#include <iostream>

#include "../src/winsock/winsock_utils.h"

int main() {
  if (initialize_winsock()) {
    std::cout << "[TEST] WinSock init OK" << std::endl;
    cleanup_winsock();
  } else {
    std::cerr << "[TEST] WinSock init FAILED" << std::endl;
    return 1;
  }

  return 0;
}