#pragma once

#include "../Entity.hpp"

class Rectangle : public Entity {
public:
    Rectangle(sf::Vector2f position, sf::Vector2f size, std::string image);
    Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    Rectangle(Rectangle const &copy);
    ~Rectangle() {}
    void setTextureRect(sf::IntRect intRect);
    sf::Vector2f getPosition() const;
    virtual void setPosition(sf::Vector2f position);
    sf::Vector2f getSize() const;
    void setSize(sf::Vector2f size);
    void move(sf::Vector2f pos);
    bool getClicked(sf::Event event);
    virtual void draw(std::shared_ptr<sf::RenderWindow> window);

protected:
    sf::RectangleShape _rect;
    sf::Texture _texture;
    bool _lastClick;
};
