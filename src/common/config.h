#ifndef CONFIG_H_
#define CONFIG_H_

const std::string kServer_IP = "127.0.0.1";  // Enter local Server IP address
constexpr int kPortNum = 8080;               // Enter Open working server port

// Maximum size of buffer for exchange info between server and client
constexpr int kBuffSize = 1024;
#endif  // CONFIG_H_