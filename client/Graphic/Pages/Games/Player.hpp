#pragma once

#include "../../Objects/Rectangle/Rectangle.hpp"
#include "../../Objects/Text/Text.hpp"
#include "../../../Network/Network.hpp"

class Player : public Rectangle {
public:
    Player();
    ~Player() {}
    void move(sf::Event &event);
    void shot();
    void setLabel(std::string label);
    void setPosition(sf::Vector2f position);
    void draw(std::shared_ptr<sf::RenderWindow> window);

private:
    Text _label;
    static int T;
    sf::Clock _clock;
};
