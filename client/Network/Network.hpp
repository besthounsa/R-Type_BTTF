#pragma once

#include "../Global.hpp"
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class Network {
public:
    static bool connect(std::string address, std::string port);
    static void send_to_server(std::string msg);
    static std::string receive_from_server();

private:
    static boost::asio::io_context _io_context;
    static std::unique_ptr<boost::asio::ip::udp::socket> _socket;
    static boost::asio::ip::udp::endpoint _server_endpoint;
};
