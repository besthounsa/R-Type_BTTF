#include "Paralax.hpp"

using namespace std;

Paralax::Paralax() :
    Rectangle(sf::Vector2f(0, 0), sf::Vector2f(WIDTH, HEIGHT), "./assets/backgrounds/stage.png")
{
    _intRect.top = 0;
    _intRect.left = 0;
    _intRect.width = 1600;
    _intRect.height = 768;
}

void Paralax::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (_clock.getElapsedTime().asMicroseconds() > 10000) {
        _intRect.left += 5;
        if (_intRect.left >= 1700)
            _intRect.left = 0;
        _rect.setTextureRect(_intRect);
        _clock.restart();
    }
    Rectangle::draw(window);
}
