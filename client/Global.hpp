#pragma once

#define WIDTH 1100
#define HEIGHT 600

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <memory>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player;
class Enemy;
class Shot;

enum Connexion {
    Disconnected = 0,
    ConnectRequest = 1,
    WaitingResponse = 2,
    Connected = 3
};

typedef struct {

    std::string address, port, playerName;
    int playerId, nbRoom;
    Connexion networkState;

    std::map<int, std::shared_ptr<Player>> players;
    std::map<int, std::shared_ptr<Enemy>> enemies;
    std::map<int, std::shared_ptr<Shot>> shots;

} GameData;

std::vector<std::string> split(std::string str, char sep);
