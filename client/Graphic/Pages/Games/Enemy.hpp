#pragma once

#include "../../Objects/Rectangle/Rectangle.hpp"

class Enemy : public Rectangle {
public:
    Enemy();
    ~Enemy() {}
    void draw(std::shared_ptr<sf::RenderWindow> window);
private:
    sf::IntRect _intRect;
    sf::Clock clock;
};
