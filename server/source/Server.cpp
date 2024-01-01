#include "../include/Server.hpp"

using namespace std;

Server::Server(boost::asio::io_service &io_service, int port) : server_socket(io_service,
    boost::asio::ip::udp::endpoint(boost::asio::ip::address_v4::any(), port))
{
    clientId = 0;
    recvFrom();
}

Server::~Server()
{
    server_socket.close();
}

void Server::handleRecv(const boost::system::error_code& error,
    size_t bytes, boost::asio::ip::udp::endpoint _clientEndpoint)
{
    auto &client = clients[clientEndpoint];
    vector<string> tab;
    int n;

    (void) error;
    (void) bytes;
    (void) _clientEndpoint;

    if (strlen(message))
        message[strlen(message) - 1] = 0;
    tab = split(message, ':');

    switch (stoi(tab[0])) {

    case 200: // client se connecte
        clients[clientEndpoint] = make_shared<Client>(clientEndpoint, tab[1]);
        sendTo(clientEndpoint, "200:" + to_string(clients[clientEndpoint]->id) + "\n");
        break;

    case 201: // client se deconnecte
        clients.erase(clientEndpoint);
        sendTo(clientEndpoint, "201:\n");
        break;

    case 202: // client bouge en haut
        if (client->y > 0)
            client->y -= 0.5;
        goto case_206;

    case 203: // client bouge en bas
        if (client->y < HEIGHT - client->size_y)
            client->y += 0.5;
        goto case_206;

    case 204: // client bouge a gauche
        if (client->x > 0)
            client->x -= 0.5;
        goto case_206;

    case 205: // client bouge a droite
        if (client->x < WIDTH - client->size_x)
            client->x += 0.5;
        goto case_206;

    case 206: // liste room players
    case_206:
        client->room->sendTo("206" + client->room->get_clients_positions());
        break;

    case 208: // client tire
        client->room->shots.push_back(make_shared<Shot>(client));
        break;

    case 210: // creer un room
        rooms.push_back(make_shared<Room>(this));
        sendTo(clientEndpoint, "211:" + to_string(rooms.size()) + "\n");
        break;

    case 211: // lister les rooms
        sendTo(clientEndpoint, "211:" + to_string(rooms.size()) + "\n");
        break;

    case 212: // joindre une room
        n = stoi(tab[1]);
        if (rooms[n]->clients.size() == 4)
            break;
        rooms[n]->clients.push_back(clients[clientEndpoint]);
        client->room = rooms[n];
        client->room->sendTo("206" + client->room->get_clients_positions());
        break;
    }
    recvFrom();
}

string Server::recvFrom(void)
{
    memset(message, 0, 1024);
    server_socket.async_receive_from(
        boost::asio::buffer(message, 1024),
        clientEndpoint,
        boost::bind(
            &Server::handleRecv,
            this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred,
            clientEndpoint
        )
    );
    return (message);
}

void Server::sendTo(boost::asio::ip::udp::endpoint endpoint, string message)
{
    server_socket.async_send_to(
        boost::asio::buffer(message), endpoint,
        boost::bind(
            &Server::handleSend, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void Server::handleSend(string message, const boost::system::error_code& error, size_t bytes)
{
    (void) message;
    (void) error;
    (void) bytes;
}

vector<string> split(string str, char sep)
{
    istringstream stream(str);
    vector<string> tab;
    string tmp;

    while (getline(stream, tmp, sep))
        if (!tmp.empty())
            tab.push_back(tmp);
    return (tab);
}

int main(int ac, char **av)
{
    int port;

    try {
        if (ac != 2)
            throw invalid_argument("invalid port");
        port = stoi(av[1]);
    }
    catch (exception &e) {
        cerr << "invalid argument: " << e.what() << endl;
        return (84);
    }
    boost::asio::io_service service;
    Server network(service, port);
    service.run();
    return 0;
}
