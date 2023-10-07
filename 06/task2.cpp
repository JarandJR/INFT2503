#include <iostream>
#include "server/server.cpp"

using namespace std;

int main() {
    Server echo_server = Server(8080);
    cout << "Starting echo server" << endl
         << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;
    echo_server.start();

}