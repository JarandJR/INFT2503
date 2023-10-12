#include "server/server.cpp"
#include <iostream>

int main() {
    Server server;

    std::cout << "Starting echo server" << std::endl
         << "Connect in a terminal with: telnet localhost 8080." << std::endl;

    server.start();
}