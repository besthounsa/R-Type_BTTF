#pragma once

#include "../../Objects/Rectangle/Rectangle.hpp"

class Paralax : public Rectangle {
public:
    Paralax();
    ~Paralax() {}
    void draw(std::shared_ptr<sf::RenderWindow> window);

private:
    sf::Clock _clock;
    sf::IntRect _intRect;
};
