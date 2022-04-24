#define SERVER 0
#if SERVER

/*
Socket Programming
https://www.codeproject.com/Articles/1264257/Socket-Programming-in-Cplusplus-using-boost-asio-T
*/

#include <iostream>
#include <boost/asio.hpp>

// tcp --> boost::asio::ip::tcp
// rest of the things from boost are --> boost::asio
using namespace boost::asio;
using ip::tcp;

std::string read_(tcp::socket &socket);
void send_(tcp::socket &socket, const std::string &message);

int main(int argc, char *argv[])
{
    boost::asio::io_service io_service;
    // listen for new connection
    tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234));
    // socket creation
    tcp::socket socket_(io_service);
    // waiting for connection
    acceptor_.accept(socket_);
    // read opeeration
    std::string message = read_(socket_);
    std::cout << message << "\n";
    // write operation
    send_(socket_, "Hello from the Server");
    std::cout << "Server sent Hello message to the client\n";

    return 0;
}

std::string read_(tcp::socket &socket)
{
    streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char *>(buf.data());
    return data;
}

void send_(tcp::socket &socket, const std::string &message)
{
    const std::string msg = message + "\n";
    write(socket, buffer(message));
}
#endif
