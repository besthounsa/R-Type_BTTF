#pragma once

#include "../APage.hpp"

class MenuPage : public APage {
public:
    MenuPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    ~MenuPage() {}
    std::string run(GameData &data);
    void draw();

private:
    std::unique_ptr<Rectangle> _backgroundImage, _playButton, _exitButton;
    std::unique_ptr<Text> _title;
};
