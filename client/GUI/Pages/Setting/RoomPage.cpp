#include "RoomPage.hpp"

using namespace std;

RoomPage::RoomPage(shared_ptr<sf::RenderWindow> window, sf::Event &event) : APage(window, event)
{
    _backgroundImage = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), "./assets/backgrounds/background2.jpg");
    _gradient = make_unique<Rectangle>(sf::Vector2f(0, 0),
        sf::Vector2f(WIDTH, HEIGHT), sf::Color(0, 0, 0, 192));
    _title = make_unique<Text>(sf::Vector2f(400, 30), "Rooms", 65);
    _addRoomButton = make_unique<Rectangle>(sf::Vector2f(900, 200),
        sf::Vector2f(110, 40), "./assets/sprites/CREATE.png");
}

string RoomPage::run(GameData &data)
{
    add_room(data.nbRoom);
    if (data.players.find(data.playerId) != data.players.end())
        return ("game");
    for (auto &room : _rooms)
        if (room.second->getClicked(_event))
            Network::send_to_server("212:" + to_string(room.first) + "\n");
    if (_addRoomButton->getClicked(_event))
        Network::send_to_server("210\n");
    draw();
    return ("");
}

void RoomPage::add_room(int nbRoom)
{
    sf::Vector2f roomPos(350, 200);

    for (int i = 0; i < nbRoom; roomPos.y += 70, i++)
        if (_rooms.find(i) == _rooms.end())
            _rooms[i] = make_unique<Rectangle>(
                roomPos, sf::Vector2f(420, 50),
                sf::Color(255, 255, 255, 50)
            );
}

void RoomPage::draw()
{
    _backgroundImage->draw(_window);
    _gradient->draw(_window);
    _title->draw(_window);
    _addRoomButton->draw(_window);
    for (auto &room : _rooms) {
        Text(
            room.second->getPosition() + sf::Vector2f(30, 15),
            "Room " + to_string(room.first), 20
        ).draw(_window);
        room.second->draw(_window);
    }
}
