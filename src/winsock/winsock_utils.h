#ifndef WINSOCK_UTILS_H_
#define WINSOCK_UTILS_H_

// Ініціалізація бібліотеки WinSock (WSAStartup)
bool initialize_winsock();

// Завершення роботи бібліотеки WinSock (WSACleanup)
void cleanup_winsock();

#endif  // WINSOCK_UTILS_H_