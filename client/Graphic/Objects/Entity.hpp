#pragma once

#include "../../Global.hpp"

class Entity {
public:
    Entity();
    ~Entity() {}
    std::string getId();
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;

protected:
    int _id;
};
