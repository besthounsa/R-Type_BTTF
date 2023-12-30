#include "Player.hpp"

using namespace std;

int Player::T = 1;

Player::Player() : Rectangle(sf::Vector2f(), sf::Vector2f(
    50, 50), "./assets/sprites/player" + to_string(T) + ".png")
{
    T++;
}

void Player::move(sf::Event &event)
{
    if (event.type != sf::Event::KeyPressed)
        return;
    if (event.key.code == sf::Keyboard::Up)
        Network::send_to_server("202\n");
    if (event.key.code == sf::Keyboard::Down)
        Network::send_to_server("203\n");
    if (event.key.code == sf::Keyboard::Left)
        Network::send_to_server("204\n");
    if (event.key.code == sf::Keyboard::Right)
        Network::send_to_server("205\n");
}

void Player::shot()
{
    if (_clock.getElapsedTime().asMicroseconds() > 500000) {
        Network::send_to_server("208\n");
        _clock.restart();
    }
}

void Player::setLabel(string label)
{
    _label.setString(label);
}

void Player::setPosition(sf::Vector2f position)
{
    Rectangle::setPosition(position);
    _label.setPosition(sf::Vector2f(position.x, position.y - 10));
}

void Player::draw(shared_ptr<sf::RenderWindow> window)
{
    Rectangle::draw(window);
    _label.draw(window);
}
