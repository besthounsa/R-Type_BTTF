#include "Text.hpp"

using namespace std;

Text::Text()
{
    _font.loadFromFile("./assets/fonts/font.ttf");
    _text.setFont(_font);
    _text.setString("");
    _text.setPosition(0, 0);
    _text.setCharacterSize(0);
    _text.setFillColor(sf::Color::White);
}

Text::Text(sf::Vector2f textPosition, string text, unsigned int size)
{
    _font.loadFromFile("./assets/fonts/font.ttf");
    _text.setFont(_font);
    _text.setString(text);
    _text.setPosition(textPosition);
    _text.setCharacterSize(size);
    _text.setFillColor(sf::Color::White);
}

Text::Text(Text const &copy) : Entity()
{
    _font = copy._font;
    _text.setFont(_font);
    _text.setString(copy._text.getString());
    _text.setPosition(copy._text.getPosition());
    _text.setCharacterSize(copy._text.getCharacterSize());
    _text.setFillColor(copy._text.getFillColor());
}

void Text::draw(shared_ptr<sf::RenderWindow> window)
{
    window->draw(_text);
}

string Text::getString()
{
    return (_text.getString());
}

void Text::setString(string str)
{
    _text.setString(str);
}

sf::Vector2f Text::getPosition()
{
    return (_text.getPosition());
}

void Text::setPosition(sf::Vector2f position)
{
    _text.setPosition(position);
}
