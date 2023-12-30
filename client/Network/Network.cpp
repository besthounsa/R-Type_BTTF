#include "Network.hpp"

using namespace std;

boost::asio::io_context Network::_io_context;
std::unique_ptr<boost::asio::ip::udp::socket> Network::_socket;
boost::asio::ip::udp::endpoint Network::_server_endpoint;

bool Network::connect(string address, string port)
{
    unique_ptr<boost::asio::ip::udp::resolver> resolver;

    try {
        _socket = make_unique<boost::asio::ip::udp::socket>(_io_context);
        resolver = make_unique<boost::asio::ip::udp::resolver>(_io_context);
        _server_endpoint = *resolver->resolve(address, port).begin();
        _socket->open(boost::asio::ip::udp::v4());
    }
    catch (exception &e) {
        return (false);
    }
    return (true);
}

void Network::send_to_server(string message)
{
    try {
        _socket->send_to(boost::asio::buffer(message), _server_endpoint);
        cout << "\nsend:" << message;
    }
    catch(exception &error) {
        cerr << error.what() << endl;
    }
}

string Network::receive_from_server()
{
    array<char, 1024> receive_buffer;
    boost::asio::ip::udp::endpoint sender_endpoint;
    boost::system::error_code error;
    size_t bytesReceived = _socket->receive_from(
        boost::asio::buffer(receive_buffer),
        sender_endpoint, 0, error);
    string message(receive_buffer.data(), bytesReceived);

    if (message != "" && message.back() == '\n')
        message.pop_back();
    cout << "recv:" << message << endl;
    return (message);
}
