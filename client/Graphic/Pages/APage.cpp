#include "APage.hpp"

using namespace std;

APage::APage(shared_ptr<sf::RenderWindow> window, sf::Event &event) :
    Rectangle(sf::Vector2f(0, 0), sf::Vector2f(WIDTH, HEIGHT), sf::Color::Transparent),
    _event(event)
{
    _window = window;
}
