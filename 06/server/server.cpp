#include <boost/asio.hpp>
#include <iostream>
#include "connection.cpp"

using namespace std;
using namespace boost::asio::ip;

class Server {
private:
    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();

        async_read_until(connection->socket, *read_buffer, "\r\n",
        [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
            if (!ec) {
                istream read_stream(read_buffer.get());
                string message;
                getline(read_stream, message);
                message.pop_back();
                if(message.find("GET") == string::npos)
                    return;

                string response;
                string body;

                cout << "Message from a connected client: " << message << endl;
                auto write_buffer = make_shared<boost::asio::streambuf>();
                ostream write_stream(write_buffer.get());

                if(message == "GET / HTTP/1.1"){
                    message = "Dette er hovedsiden";
                    body = "<html><body><h1>" + message + "</h1>"
                                        "<a href=\"/en_side\">En side</a>"
                                        "<p>\"\"</p>"
                                        "<a href=\"/404\">404</a>"
                            "</body></html>";
                    response = "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(body.length()) + "\r\n\r\n" + body;
                }else if(message == "GET /en_side HTTP/1.1"){
                    message = "Dette er en side";
                    body = "<html><body><h1>" + message + "</h1><a href=\"/\">Hjem</a></body></html>";
                    response = "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(body.length()) + "\r\n\r\n" + body;
                } else{
                    message = "404 Not Found";
                    body = "<html><body><h1>" + message + "</h1><a href=\"/\">Hjem</a></body></html>";
                    response = "HTTP/1.1 404 Not Found\r\nContent-Length: " + std::to_string(body.length()) + "\r\n\r\n" + body;
                }
                write_stream << response << "\r\n";

                async_write(connection->socket, *write_buffer,
                    [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                        if (!ec)
                            handle_request(connection);
                    });
            }
        });
    }

    void accept() {
        auto connection = make_shared<Connection>(io_service);

        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    Server() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};