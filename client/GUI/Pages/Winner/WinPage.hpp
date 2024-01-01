#pragma once

#include "../APage.hpp"

class WinPage : public APage {
public:
    WinPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    ~WinPage() {}
    std::string run(GameData &data);
    void draw();

private:
    std::unique_ptr<Rectangle> _backgroundImage, _gradient, _exitButton;
    std::unique_ptr<Text> _title;
};
