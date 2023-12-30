#pragma once

#include "Graphic/Graphics.hpp"
#include "Network/Network.hpp"

class Core {
public:
    Core();
    ~Core();
    void run();
    void response_management();

    static void unCompressPlayers(GameData &data, std::vector<std::string> tab);
    static void unCompressEnemies(GameData &data, std::vector<std::string> tab);
    static void unCompressShots(GameData &data, std::vector<std::string> tab);

private:
    std::unique_ptr<GUI> _graphics;
    std::unique_ptr<Network> _network;
    boost::thread _thread;
    GameData _data;
    int _start;
};
