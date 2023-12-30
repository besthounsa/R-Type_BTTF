#pragma once

#include "../APage.hpp"

class OverPage : public APage {
public:
    OverPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    ~OverPage() {}
    std::string run(GameData &data);
    void draw();

private:
    std::unique_ptr<Rectangle> _backgroundImage, _gradient, _exitButton;
    std::unique_ptr<Text> _title;
};
