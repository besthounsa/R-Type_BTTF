#pragma once

#include "../APage.hpp"
#include "Paralax.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"

class GamePage : public APage {
public:
    GamePage(std::shared_ptr<sf::RenderWindow> window, sf::Event &myEvent);
    ~GamePage() {}
    std::string run(GameData &data);
    void draw();

private:
    std::unique_ptr<Paralax> _paralax;
    std::map<int, std::shared_ptr<Player>> _players;
    std::map<int, std::shared_ptr<Enemy>> _enemies;
    std::map<int, std::shared_ptr<Shot>> _shots;
};
