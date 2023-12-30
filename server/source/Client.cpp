#include "../include/Client.hpp"

using namespace std;

Client::Client(boost::asio::ip::udp::endpoint _endPoint, std::string _name) :
    Entity(0, 0, 50, 50)
{
    endPoint = _endPoint;
    name = _name;
    life = 5;
}
