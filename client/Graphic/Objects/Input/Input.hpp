#pragma once

#include "../Rectangle/Rectangle.hpp"
#include "../Text/Text.hpp"

class Input : public Rectangle {
public:
    Input(Text label, Rectangle inputRect, Text inputText);
    Input(Input const &copy);
    ~Input() {}
    void write(sf::Event &event);
    bool getActive();
    void setActive(bool active);
    std::string getString();
    void setString(std::string &str);
    void draw(std::shared_ptr<sf::RenderWindow> window);

private:
    bool _active;
    Text _label;
    Text _inputText;
    sf::Clock _clock;
};
