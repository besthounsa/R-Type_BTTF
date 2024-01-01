#include "Input.hpp"

using namespace std;

Input::Input(Text label, Rectangle inputRect, Text inputText) :
    Rectangle(inputRect), _label(label), _inputText(inputText)
{
    _active = false;
}

Input::Input(Input const &copy) : Rectangle(copy),
    _label(copy._label), _inputText(copy._inputText)
{
    _active = copy._active;
}

void Input::write(sf::Event &event)
{
    string textStr = _inputText.getString();

    if (!_active || _clock.getElapsedTime().asMilliseconds() < 100)
        return;
    textStr.pop_back();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        if (textStr != "")
            textStr.pop_back();
    } else if (event.type == sf::Event::TextEntered) {
        char c = event.text.unicode;
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.')
            textStr += c;
    }
    textStr += '_';
    _inputText.setString(textStr);
    _clock.restart();
}

bool Input::getActive()
{
    return (_active);
}

void Input::setActive(bool active)
{
    string textStr = _inputText.getString();

    if (!active && _active)
        textStr.pop_back();
    if (active && !_active)
        textStr += '_';
    _inputText.setString(textStr);
    _active = active;
}

string Input::getString()
{
    return (_inputText.getString());
}

void Input::setString(string &str)
{
    _inputText.setString(str);
}

void Input::draw(shared_ptr<sf::RenderWindow> window)
{
    _label.draw(window);
    Rectangle::draw(window);
    _inputText.draw(window);
}
