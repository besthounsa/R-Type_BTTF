#pragma once

#include "../Entity.hpp"

class Text : public Entity {
public:
    Text();
    Text(sf::Vector2f textPosition, std::string text, unsigned int size);
    Text(Text const &copy);
    ~Text() {}
    void draw(std::shared_ptr<sf::RenderWindow> window);
    std::string getString();
    void setString(std::string str);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);

private:
    sf::Text _text;
    sf::Font _font;
};
