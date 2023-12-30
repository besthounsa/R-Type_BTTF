#include "LoginPage.hpp"

using namespace std;

LoginPage::LoginPage(shared_ptr<sf::RenderWindow> window, sf::Event &event) :
    APage(window, event)
{
    _backgroundImage = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), "./assets/backgrounds/background2.jpg");
    _gradient = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), sf::Color(0, 0, 0, 192));
    _title = make_unique<Text>(sf::Vector2f(400, 30), "Connection", 65);
    _address = make_unique<Input>(
        Text(sf::Vector2f(400, 170), "Adresse", 17),
        Rectangle(sf::Vector2f(400, 200), sf::Vector2f(300, 30), sf::Color(255, 255, 255, 45)),
        Text(sf::Vector2f(410, 208), "192.168.1.108", 12)
    );
    _port = make_unique<Input>(
        Text(sf::Vector2f(400, 245), "Port", 17),
        Rectangle(sf::Vector2f(400, 275), sf::Vector2f(300, 30), sf::Color(255, 255, 255, 45)),
        Text(sf::Vector2f(410, 283), "8080", 12)
    );
    _name = make_unique<Input>(
        Text(sf::Vector2f(400, 320), "Name", 17),
        Rectangle(sf::Vector2f(400, 350), sf::Vector2f(300, 30), sf::Color(255, 255, 255, 45)),
        Text(sf::Vector2f(410, 358), "Mouamar", 12)
    );
    _nextPageButton = make_unique<Rectangle>(sf::Vector2f(400, 420),
        sf::Vector2f(300, 40), "assets/sprites/bouton.png");
}

string LoginPage::run(GameData &data)
{
    if (_address->getClicked(_event)) {
        _address->setActive(true);
        _port->setActive(false);
        _name->setActive(false);
    }
    if (_port->getClicked(_event)) {
        _address->setActive(false);
        _port->setActive(true);
        _name->setActive(false);
    }
    if (_name->getClicked(_event)) {
        _address->setActive(false);
        _port->setActive(false);
        _name->setActive(true);
    }
    if (_address->getActive())
        _address->write(_event);
    if (_port->getActive())
        _port->write(_event);
    if (_name->getActive())
        _name->write(_event);

    data.address = _address->getString();
    data.port = _port->getString();
    data.playerName = _name->getString();
    draw();

    if (data.networkState == Connected)
        return ("room");
    if (_nextPageButton->getClicked(_event))
        data.networkState = ConnectRequest;
    return ("");
}
 
void LoginPage::draw()
{
    _backgroundImage->draw(_window);
    _gradient->draw(_window);
    _title->draw(_window);
    _address->draw(_window);
    _port->draw(_window);
    _name->draw(_window);
    _nextPageButton->draw(_window);
}
