#include "Enemy.hpp"

using namespace std;

Enemy::Enemy() : Rectangle(sf::Vector2f(WIDTH, rand() % (HEIGHT - 50)),
    sf::Vector2f(50, 40), "./assets/sprites/mechant1.png")
{
    _intRect.top = 0;
    _intRect.left = 0;
    _intRect.width = 65;
    _intRect.height = 48;
}

void Enemy::draw(shared_ptr<sf::RenderWindow> window)
{
    if (clock.getElapsedTime().asMicroseconds() > 10000) {
        _intRect.left += 65;
        if (_intRect.left >= 195)
            _intRect.left = 0;
        setTextureRect(_intRect);
        clock.restart();
    }
    Rectangle::draw(window);
}
