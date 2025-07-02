#include <iostream>

#include "../src/winsock/winsock_utils.h"

int main() {
  if (!initialize_winsock()) return 1;
  cleanup_winsock();

  return 0;
}