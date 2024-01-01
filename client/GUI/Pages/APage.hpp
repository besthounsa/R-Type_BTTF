#pragma once

#include "../Objects/Input/Input.hpp"
#include "../../Network/Network.hpp"

class APage : public Rectangle {
public:
    APage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    virtual std::string run(GameData &data) = 0;
    virtual ~APage() {}

protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::unique_ptr<sf::Music> _pageSong;
    sf::Event &_event;
};
