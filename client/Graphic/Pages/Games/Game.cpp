#include "Game.hpp"

using namespace std;

GamePage::GamePage(shared_ptr<sf::RenderWindow> window, sf::Event &event) :
    APage(window, event)
{
    _paralax = make_unique<Paralax>();
}

string GamePage::run(GameData &data)
{
    _players = data.players;
    _enemies = data.enemies;
    _shots = data.shots;

    if (_players.find(data.playerId) == _players.end())
        return ("over");
    if (_event.type == sf::Event::TextEntered && _event.text.unicode == ' ')
        _players[data.playerId]->shot();
    _players[data.playerId]->move(_event);
    draw();
    return ("");
}

void GamePage::draw()
{
    _paralax->draw(_window);
    for (auto &actor : _players)
        actor.second->draw(_window);
    for (auto &shot : _shots)
        shot.second->draw(_window);
    for (auto &enemy : _enemies)
        enemy.second->draw(_window);
}
