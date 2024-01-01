#include "WinPage.hpp"

using namespace std;

WinPage::WinPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event) :
    APage(window, event)
{
    _backgroundImage = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), "./assets/backgrounds/background.jpg");
    _gradient = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), sf::Color(0, 0, 0, 192));
    _title = make_unique<Text>(sf::Vector2f(WIDTH / 2 - 180, HEIGHT / 2 - 110), "YOU WON", 60);
    _exitButton = make_unique<Rectangle>(sf::Vector2f(WIDTH / 2 - 65, HEIGHT / 2 + 80),
        sf::Vector2f(140, 45), "./assets/sprites/EXIT.png");
}

string WinPage::run(GameData &data)
{
    (void) data;
    if (_exitButton->getClicked(_event))
        return ("exit");
    draw();
    return ("");
}

void WinPage::draw()
{
    _backgroundImage->draw(_window);
    _gradient->draw(_window);
    _title->draw(_window);
    _exitButton->draw(_window);
}
