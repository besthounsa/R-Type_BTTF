#include "Graphics.hpp"

using namespace std;

GUI::GUI(GameData &data) : _data(data)
{
    _window = make_shared<sf::RenderWindow>(
        sf::VideoMode(WIDTH, HEIGHT), "MY R-TYPE",
        sf::Style::Resize | sf::Style::Close
    );
    srand(time(0));
    _page = make_unique<MenuPage>(_window, _event);
    _click.openFromFile("./assets/songs/click.ogg");
    _game.openFromFile("./assets/songs/menu_music.ogg");
    // _game.play();
}

bool GUI::manage_event()
{
    while (_window->pollEvent(_event))
        if (_event.type == sf::Event::Closed)
            return (false);
    if (_event.type == sf::Event::MouseButtonPressed)
        _click.play();
    return (true);
}

bool GUI::runPage()
{
    if (_currentPage == "menu")
        _page = make_unique<MenuPage>(_window, _event);
    if (_currentPage == "connect")
        _page = make_unique<LoginPage>(_window, _event);
    if (_currentPage == "room")
        _page = make_unique<RoomPage>(_window, _event);
    if (_currentPage == "game")
        _page = make_unique<GamePage>(_window, _event);
    if (_currentPage == "over")
        _page = make_unique<OverPage>(_window, _event);
    _window->clear();
    _currentPage = _page->run(_data);
    _window->display();
    if (_currentPage == "exit")
        return (false);
    return (true);
}
