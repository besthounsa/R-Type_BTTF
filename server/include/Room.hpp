#pragma once

#include "Server.hpp"
#include "Client.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"

class Server;
class Shot;

class Room {
public:
    Room(Server *myServer);
    ~Room();
    static void manage_room(void *data);
    void sendTo(std::string msg);
    std::string get_clients_positions();
    std::string get_enemies_positions();
    std::string get_shots_positions();

    void collision();
    void enemy_out();
    void shot_out();
    void enemy_client();
    void enemy_shot();
    void win_condition();

    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Shot>> shots;
    boost::thread myThread;
    Server *server;
};
