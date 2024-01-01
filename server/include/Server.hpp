#pragma once

#include "Entity.hpp"
#include "Room.hpp"
#include "Client.hpp"

class Room;
class Client;

class Server {
public:
    Server(boost::asio::io_service &io_service, int port);
    ~Server();
    std::string recvFrom(void);
    void handleRecv(const boost::system::error_code& error,
        std::size_t bytes, boost::asio::ip::udp::endpoint _clientEndpoint);
    void sendTo(boost::asio::ip::udp::endpoint endpoint, std::string message);
    void handleSend(std::string message, const boost::system::error_code& error, std::size_t bytes);

private:
    boost::asio::ip::udp::socket server_socket;
    boost::asio::ip::udp::endpoint clientEndpoint;
    char message[1024];
    std::map<boost::asio::ip::udp::endpoint, std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Room>> rooms;
    int clientId;
};

std::vector<std::string> split(std::string str, char sep);
