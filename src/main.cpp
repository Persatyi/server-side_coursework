#include <winsock2.h>

#include <iostream>
#include <string>

#include "client_session.h"
#include "config.h"
#include "connection_utils.h"
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

  // Client socket creation and acception in case of connection
  SOCKET client_socket = accept_client(server_socket);
  if (client_socket == INVALID_SOCKET) {
    std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError()
              << std::endl;
    closesocket(server_socket);
    cleanup_winsock();
    return 1;
  } else {
    // Наприклад, можна щось надіслати клієнту:
    std::string welcome = "Welcome!\n";
    send(client_socket, welcome.c_str(), welcome.size(), 0);
  }

  // Exchange text data between Server and Client. Disconnection if a client send "xxx"
  handle_client_session(client_socket);

  // Закриваємо клієнта після обробки
  closesocket(client_socket);
  closesocket(server_socket);
  cleanup_winsock();

  return 0;
}