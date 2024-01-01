#include "../include/Room.hpp"

using namespace std;

Room::Room(Server *myServer)
{
    server = myServer;
    myThread = boost::thread(boost::bind(&Room::manage_room, this));
}

Room::~Room()
{
    myThread.join();
}

void Room::manage_room(void *data)
{
    Room *room = (Room*) data;
    string tmp;
    int n = 0;

    while (true) {
        room->collision();
        for (auto &shot : room->shots) shot->x += 3;
        room->sendTo("208" + room->get_shots_positions());
        for (auto &enemy : room->enemies) enemy->x -= 1;
        room->sendTo("209" + room->get_enemies_positions());
        if (n == 100) {
            room->enemies.push_back(make_shared<Enemy>());
            n = 0;
        } else n++;
        boost::this_thread::sleep_for(boost::chrono::microseconds(10000));
    }
}

void Room::sendTo(string msg)
{
    for (auto &client : clients)
        server->sendTo(client->endPoint, msg);
}

string Room::get_clients_positions()
{
    string msg(":");

    for (auto &client : clients)
        msg += to_string(client->id) + "," +
            to_string(client->x) + "," +
            to_string(client->y) + "," +
            client->name + "," +
            to_string(client->life) + "," +
            to_string(client->score) + ";";
    msg.back() = '\n';
    return (msg);
}

string Room::get_enemies_positions()
{
    string msg(":");

    for (auto &enemy : enemies)
        msg += to_string(enemy->id) + "," +
            to_string(enemy->x) + "," +
            to_string(enemy->y) + ";";
    msg.back() = '\n';
    return (msg);
}

string Room::get_shots_positions()
{
    string msg(":");

    for (auto &shot : shots)
        msg += to_string(shot->id) + "," +
            to_string(shot->x) + "," +
            to_string(shot->y) + ";";
    msg.back() = '\n';
    return (msg);
}




void Room::collision()
{
    std::vector<std::shared_ptr<Client>> copy = clients;

    enemy_out();
    shot_out();
    enemy_shot();
    win_condition();
    enemy_client();
    for (auto &tmp : copy)
        server->sendTo(tmp->endPoint, "206" + get_clients_positions());
}

void Room::enemy_out()
{
    vector<vector<shared_ptr<Enemy>>::iterator> delEnemies;

    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
        if ((*enemy)->x < -(*enemy)->size_x)
            delEnemies.push_back(enemy);
    for (auto &tmp : delEnemies)
        enemies.erase(tmp);
}

void Room::shot_out()
{
    vector<vector<shared_ptr<Shot>>::iterator> delShots;

    for (auto shot = shots.begin(); shot != shots.end(); shot++)
        if ((*shot)->x > WIDTH)
            delShots.push_back(shot);
    for (auto &tmp : delShots)
        shots.erase(tmp);
}

void Room::enemy_client()
{
    vector<vector<shared_ptr<Enemy>>::iterator> delEnemies;
    vector<vector<shared_ptr<Client>>::iterator> delClients;

    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
        for (auto client = clients.begin(); client != clients.end(); client++)
            if ((*client)->collision(*enemy) || (*enemy)->collision(*client)) {
                (*client)->life--;
                if (!(*client)->life)
                    delClients.push_back(client);
                delEnemies.push_back(enemy);
                break;
            }
    for (auto &tmp : delEnemies)
        enemies.erase(tmp);
    for (auto &tmp : delClients)
        clients.erase(tmp);
}

void Room::enemy_shot()
{
    vector<vector<shared_ptr<Enemy>>::iterator> delEnemies;
    vector<vector<shared_ptr<Shot>>::iterator> delShots;

    for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
        for (auto shot = shots.begin(); shot != shots.end(); shot++)
            if ((*shot)->collision(*enemy) || (*enemy)->collision(*shot)) {
                delEnemies.push_back(enemy);
                delShots.push_back(shot);
                (*shot)->client->score++;
                break;
            }
    for (auto &tmp : delEnemies)
        enemies.erase(tmp);
    for (auto &tmp : delShots)
        shots.erase(tmp);
}

void Room::win_condition()
{
    vector<vector<shared_ptr<Client>>::iterator> delClients;

    for (auto client = clients.begin(); client != clients.end(); client++)
        if ((*client)->score >= 5) {
            delClients.push_back(client);
            server->sendTo((*client)->endPoint, "300\n");
            // (*client)->room->clients.erase( (*client)->room->clients.find() );
        }
    for (auto &tmp : delClients)
        clients.erase(tmp);
}
