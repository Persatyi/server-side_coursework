#define WIN32_LEAN_AND_MEAN  // Оптимізація заголовків <windows.h>

#include <windows.h>   // Базові типи та макроси Windows API
#include <winsock2.h>  // Основні сокет-функції (WSAStartup, socket, і т.д.)
#include <ws2tcpip.h>  // Сучасні функції (InetPton, getaddrinfo, IPv6)

#include <iostream>

#pragma comment(lib, "ws2_32.lib")  // Автоматично додає бібліотеку Ws2_32.lib для лінкування

bool initialize_winsock() {
  WORD wVersionRequested;
  WSADATA wsaData;
  int errStat;  // Socket status after startup

  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
  wVersionRequested = MAKEWORD(2, 2);

  errStat = WSAStartup(wVersionRequested, &wsaData);  //  WinSocks initialization

  if (errStat != 0) {
    std::cout << "WSAStartup failed with error: " << errStat << "\n";
    return false;
  }

  /*
  Confirm that the WinSock DLL supports 2.2.
 Note that if the DLL supports versions greater than 2.2 in addition to 2.2, it will still
 return 2.2 in wVersion since that is the version we requested.
 */
  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
    std::cout << "Could not find a usable version of Winsock.dll\n";
    WSACleanup();
    return false;
  } else {
    std::cout << "The Winsock 2.2 dll was found okay\n";
  }

  return true;
}

void cleanup_winsock() {
  WSACleanup();
}