#pragma once

#include "Room.hpp"

class Room;

class Client : public Entity {
public:
    Client(boost::asio::ip::udp::endpoint _endPoint, std::string _name);

    boost::asio::ip::udp::endpoint endPoint;
    std::string name;
    std::shared_ptr<Room> room;
    int life;
    int score;
};
