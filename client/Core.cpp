#include "Core.hpp"

using namespace std;

Core::Core()
{
    _start = true;
    _data.networkState = Disconnected;
    _data.nbRoom = 0;
    _data.winner = false;
    _graphics = make_unique<GUI>(_data);
    _network = make_unique<Network>();
    _thread = boost::thread(boost::bind(&Core::response_management, this));
}

void Core::run()
{
    while (_graphics->manage_event() && _graphics->runPage()) {
        if (_data.networkState != ConnectRequest)
            continue;
        if (_network->connect(_data.address, _data.port)) {
            _network->send_to_server("200:" + _data.playerName + "\n");
            _data.networkState = WaitingResponse;
        } else {
            _data.networkState = Disconnected;
        }
    }
}

Core::~Core()
{
    _start = false;
    if (_data.networkState == Connected) {
        _network->send_to_server("201\n");
        _thread.join();
    }
}






void Core::response_management()
{
    vector<string> tab;
    string response;

    while (_start) {
        cout << "";
        if (_data.networkState != WaitingResponse &&
            _data.networkState != Connected)
            continue;
        response = _network->receive_from_server();
        tab = split(response, ':');

        switch (stoi(tab[0])) {
        case 200:
            _data.playerId = stoi(tab[1]);
            _data.networkState = Connected;
            _network->send_to_server("211\n");
            break;
        case 201:
            _data.networkState = Disconnected;
            break;
        case 300:
            _data.winner = true;
            _data.networkState = Disconnected;
            break;
        case 206:
            unCompressPlayers(_data, tab);
            break;
        case 208:
            unCompressShots(_data, tab);
            break;
        case 209:
            unCompressEnemies(_data, tab);
            break;
        case 211:
            _data.nbRoom = stoi(tab[1]);
        }
    }
}

void Core::unCompressEnemies(GameData &data, vector<string> tab)
{
    vector<string> tmp;
    vector<int> enemyIds;
    vector<int> delItems;
    int id;

    if (tab.size() < 2) {
        data.enemies.clear();
        return;
    }
    tab = split(tab[1], ';');
    for (auto &infos : tab) {
        tmp = split(infos, ',');
        if (tmp.size() < 3)
            continue;
        id = stoi(tmp[0]);
        enemyIds.push_back(id);
        if (data.enemies.find(id) == data.enemies.end())
            data.enemies[id] = make_shared<Enemy>();
        data.enemies[id]->setPosition(sf::Vector2f(
            stof(tmp[1]), stof(tmp[2])));
    }
    for (auto entity = data.enemies.begin(); entity != data.enemies.end(); entity++)
        if (find(enemyIds.begin(), enemyIds.end(), entity->first) == enemyIds.end())
            delItems.push_back(entity->first);
    for (auto &tmp : delItems) data.enemies.erase(tmp);
}

void Core::unCompressShots(GameData &data, vector<string> tab)
{
    vector<string> tmp;
    vector<int> enemyIds;
    vector<int> delItems;
    int id;

    if (tab.size() < 2) {
        data.shots.clear();
        return;
    }
    tab = split(tab[1], ';');
    for (auto &infos : tab) {
        tmp = split(infos, ',');
        if (tmp.size() < 3)
            continue;
        id = stoi(tmp[0]);
        enemyIds.push_back(id);
        if (data.shots.find(id) == data.shots.end())
            data.shots[id] = make_shared<Shot>();
        data.shots[id]->setPosition(sf::Vector2f(
            stof(tmp[1]), stof(tmp[2])));
    }
    for (auto entity = data.shots.begin(); entity != data.shots.end(); entity++)
        if (find(enemyIds.begin(), enemyIds.end(), entity->first) == enemyIds.end())
            delItems.push_back(entity->first);
    for (auto &tmp : delItems) data.shots.erase(tmp);
}

void Core::unCompressPlayers(GameData &data, vector<string> tab)
{
    vector<string> tmp;
    vector<int> enemyIds;
    vector<int> delItems;
    int id;

    if (tab.size() < 2) {
        data.players.clear();
        return;
    }
    tab = split(tab[1], ';');
    for (auto &infos : tab) {
        tmp = split(infos, ',');
        if (tmp.size() < 6)
            continue;
        id = stoi(tmp[0]);
        enemyIds.push_back(id);
        if (data.players.find(id) == data.players.end())
            data.players[id] = make_shared<Player>();
        data.players[id]->setPosition(sf::Vector2f(
            stof(tmp[1]), stof(tmp[2])));
        data.players[id]->setLabel(tmp[3] + ": " + tmp[4] + " score:" + tmp[5]);
        data.players[id]->score = stoi(tmp[5]);
    }
    for (auto entity = data.players.begin(); entity != data.players.end(); entity++)
        if (find(enemyIds.begin(), enemyIds.end(), entity->first) == enemyIds.end())
            delItems.push_back(entity->first);
    for (auto &tmp : delItems) data.players.erase(tmp);
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

int main()
{
    Core core;
    core.run();
    return (0);
}
