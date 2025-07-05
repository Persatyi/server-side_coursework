#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

SOCKET create_server_socket() {
  // Server socket initialization
  SOCKET server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (server_socket == INVALID_SOCKET) {
    return INVALID_SOCKET;
  }

  return server_socket;
}

bool bind_server_socket(SOCKET socket, int port, const std::string& ipAddress = "") {
  sockaddr_in serverInfo;
  // Initializing servInfo structure
  ZeroMemory(&serverInfo, sizeof(serverInfo));

  serverInfo.sin_family = AF_INET;    // AF_INET для інтернет підключень
  serverInfo.sin_port = htons(port);  // Переводить int порт у мережевий формат

  if (!ipAddress.empty()) {
    // Якщо IP задано явно — перетворюємо з тексту в двійковий формат
    if (inet_pton(AF_INET, ipAddress.c_str(), &serverInfo.sin_addr) <= 0) {
      std::cerr << "inet_pton failed for address: " << ipAddress << std::endl;
      return false;
    }
  } else {
    serverInfo.sin_addr = {INADDR_ANY};  // Прив'язка до всіх інтерфейсів
  }

  int result = bind(socket, reinterpret_cast<sockaddr*>(&serverInfo), sizeof(serverInfo));
  if (result == SOCKET_ERROR) {
    return false;
  }

  return true;
}

bool start_listening(SOCKET socket) {
  return listen(socket, SOMAXCONN) != SOCKET_ERROR;  // SOMAXCONN черга максимального розміру
}