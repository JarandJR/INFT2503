#include <boost/asio.hpp>

using namespace boost::asio::ip;

class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };