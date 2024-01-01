#pragma once

#include "../APage.hpp"

class RoomPage : public APage {
public:
    RoomPage(std::shared_ptr<sf::RenderWindow> window, sf::Event &event);
    ~RoomPage() {}
    std::string run(GameData &data);
    void add_room(int nbRoom);
    void draw();

private:
    std::unique_ptr<Rectangle> _backgroundImage, _gradient, _addRoomButton;
    std::unique_ptr<Text> _title;
    std::map<int, std::unique_ptr<Rectangle>> _rooms;
};
