#pragma once

#include "../APage.hpp"

class LoginPage : public APage {
public:
    LoginPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    ~LoginPage() {}
    std::string run(GameData &data);
    void draw();

private:
    std::unique_ptr<Rectangle> _backgroundImage, _gradient, _nextPageButton;
    std::unique_ptr<Text> _title;
    std::unique_ptr<Input> _address, _port, _name;
};
