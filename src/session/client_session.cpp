#include "client_session.h"

#include <cstring>
#include <iostream>
#include <vector>

#include "config.h"

void handle_client_session(SOCKET client_sock) {
  // Створюємо два буфери: servBuff — для прийому повідомлень від клієнта. clientBuff — для введення
  // тексту від сервера (хоста).
  std::vector<char> servBuff(kBuffSize), clientBuff(kBuffSize);

  // Змінна для зберігання кількості байтів, що були отримані або надіслані.
  int packet_size = 0;

  while (true) {
    // Очищаємо буфер прийому перед новим recv(), щоб не залишалися старі символи у пам’яті.
    std::fill(servBuff.begin(), servBuff.end(), 0);
    // Отримуємо дані від клієнта:
    // servBuff.data() — вказівник на початок буфера.
    // servBuff.size() — скільки байтів можна прийняти.
    // 0 — флаги (стандартні).
    packet_size = recv(client_sock, servBuff.data(), servBuff.size(), 0);

    if (packet_size <= 0) {
      break;
    }
    // Виводимо повідомлення клієнта в консоль:
    std::cout << "Client: " << std::string(servBuff.data(), packet_size) << "\n";

    // Запит серверного користувача ввести повідомлення.
    std::cout << "You: ";
    // Зчитуємо рядок з клавіатури (stdin) і записуємо його в clientBuff
    fgets(clientBuff.data(), clientBuff.size(), stdin);
    // Видаляємо символ нового рядка \n, який додає fgets()
    // Функція strcspn() шукає позицію \n і замінює його на \0
    clientBuff[strcspn(clientBuff.data(), "\n")] = '\0';

    // Якщо введене повідомлення — "xxx", сервер завершує спілкування з клієнтом і виходить з циклу.
    if (strcmp(clientBuff.data(), "xxx") == 0) {
      break;
    }

    // Відправляємо повідомлення клієнту
    packet_size = send(client_sock, clientBuff.data(), strlen(clientBuff.data()), 0);
    if (packet_size == SOCKET_ERROR) {
      std::cerr << "Can't send message to client. Error # " << WSAGetLastError() << "\n";
      break;  // Завершуємо сесію з клієнтом
    }
  }

  // Завершення сесії
  // Повідомляємо системі, що більше не будемо ні відправляти, ні приймати дані
  shutdown(client_sock, SD_BOTH);
}