#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace std;
using namespace boost::asio::ip;


class Connection {
public:
    tcp::socket socket;
    explicit Connection(boost::asio::io_service &io_service, tcp::acceptor acceptor) : socket(io_service), acceptor(acceptor) {}

    boost::asio::io_service io_service;
    tcp::acceptor acceptor;

    void handle_request(const shared_ptr <Connection>& connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        async_read_until(connection->socket, *read_buffer, "\r\n",
        [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                 istream read_stream(read_buffer.get());
                 std::string message;
                 getline(read_stream, message);
                 message.pop_back();

                 if (message == "exit") return;
                 cout << "Message from a connected client: " << message << endl;
                 auto write_buffer = make_shared<boost::asio::streambuf>();
                 ostream write_stream(write_buffer.get());
                 write_stream << message << "\r\n";

                 async_write(connection->socket, *write_buffer,
                 [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                     if (!ec) handle_request(connection);
                 });
            }
         });
    }

    void accept() {
        auto connection = make_shared<Connection>(io_service);

        acceptor.async_accept(connection->socket,
        [this, connection](const boost::system::error_code &ec) {
            accept();
            if (!ec) { handle_request(connection); }
        });
    }
};