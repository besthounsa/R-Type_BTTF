#include "Shot.hpp"

using namespace std;

Shot::Shot() : Rectangle(
    sf::Vector2f(0, 0), sf::Vector2f(30, 30),
    "./assets/sprites/yellow_missile.png")
{
}
