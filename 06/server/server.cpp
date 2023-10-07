#include <boost/asio.hpp>
#include "connection.cpp"

using namespace boost::asio::ip;

class Server {
private:
    boost::asio::io_service io_service;
    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    Connection connection;
public:
    Server(int ep) :
    ndpoint(tcp::v4(), ep),
    acceptor(io_service, endpoint),
    connection(io_service, acceptor){};

    void start() {
        connection.accept();
        connection.io_service.run();
    }
};
