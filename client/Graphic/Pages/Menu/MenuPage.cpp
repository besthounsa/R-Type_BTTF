#include "MenuPage.hpp"

using namespace std;

MenuPage::MenuPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event) :
    APage(window, event)
{
    _backgroundImage = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), "./assets/backgrounds/background.jpg");
    _title = make_unique<Text>(sf::Vector2f(WIDTH / 2 - 100, 30), "R-TYPE", 60);
    _playButton = make_unique<Rectangle>(sf::Vector2f(65, 320),
        sf::Vector2f(150, 60), "./assets/sprites/bouton.png");
    _exitButton = make_unique<Rectangle>(sf::Vector2f(65, 395),
        sf::Vector2f(150, 60), "./assets/sprites/bouton.png");
}

string MenuPage::run(GameData &data)
{
    (void) data;
    draw();
    if (_playButton->getClicked(_event))
        return ("connect");
    if (_exitButton->getClicked(_event))
        return ("exit");
    return ("");
}

void MenuPage::draw()
{
    _backgroundImage->draw(_window);
    _title->draw(_window);
    _playButton->draw(_window);
    _exitButton->draw(_window);
}
