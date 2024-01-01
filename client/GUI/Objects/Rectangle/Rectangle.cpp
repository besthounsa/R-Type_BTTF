#include "Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, string image)
{
    _lastClick = false;
    _rect.setPosition(position);
    _rect.setSize(size);
    _texture.loadFromFile(image);
    _rect.setTexture(&_texture);
}

Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    _rect.setPosition(position);
    _rect.setSize(size);
    _rect.setFillColor(color);
}

Rectangle::Rectangle(Rectangle const &copy) : Entity()
{
    sf::Color color = copy._rect.getFillColor();

    if (color != sf::Color::Transparent)
        _rect.setFillColor(color);
    _rect = copy._rect;
    _texture = copy._texture;
    _rect.setTexture(&_texture);
    _rect.setPosition(copy.getPosition());
    _rect.setSize(copy.getSize());
}

bool Rectangle::getClicked(sf::Event event)
{
    sf::Event::MouseButtonEvent mousePos;
    sf::Vector2f position = getPosition();
    sf::Vector2f toPosition = position + getSize();
    bool click = false;

    if (event.type == sf::Event::MouseButtonPressed) {
        mousePos = event.mouseButton;
        if (mousePos.x > position.x && mousePos.x < toPosition.x &&
            mousePos.y > position.y && mousePos.y < toPosition.y)
            click = true;
    }
    if (click && !_lastClick) {
        _lastClick = click;
        return (true);
    }
    _lastClick = click;
    return (false);
}

void Rectangle::draw(shared_ptr<sf::RenderWindow> window)
{
    window->draw(_rect);
}

sf::Vector2f Rectangle::getPosition() const
{
    return (_rect.getPosition());
}

void Rectangle::setPosition(sf::Vector2f position)
{
    _rect.setPosition(position);
}

sf::Vector2f Rectangle::getSize() const
{
    return (_rect.getSize());
}

void Rectangle::setSize(sf::Vector2f size)
{
    _rect.setSize(size);
}

void Rectangle::setTextureRect(sf::IntRect intRect)
{
    _rect.setTextureRect(intRect);
}

void Rectangle::move(sf::Vector2f pos)
{
    _rect.move(pos);
}
