#include "../include/Enemy.hpp"

using namespace std;

Enemy::Enemy() : Entity(WIDTH, rand() % (HEIGHT - 50), 100, 50)
{
}
