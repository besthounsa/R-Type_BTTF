#pragma once

#include "Pages/Menu/MenuPage.hpp"
#include "Pages/Setting/LoginPage.hpp"
#include "Pages/Setting/RoomPage.hpp"
#include "Pages/Games/Game.hpp"
#include "Pages/Over/OverPage.hpp"

class GUI {
public:
    GUI(GameData &data);
    ~GUI() {}
    bool manage_event();
    bool runPage();

private:
    std::shared_ptr<sf::RenderWindow> _window;
    std::unique_ptr<APage> _page;
    std::string _currentPage;
    GameData &_data;
    sf::Event _event;
    sf::Music _click;
    sf::Music _game;
};
