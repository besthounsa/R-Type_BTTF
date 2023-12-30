#include "../include/Entity.hpp"

using namespace std;

int Entity::T = 0;

Entity::Entity(double _x, double _y, double _size_x, double _size_y)
{
    id = T;
    x = _x;
    y = _y;
    size_x = _size_x;
    size_y = _size_y;
    T++;
}

bool Entity::collision(shared_ptr<Entity> entity2)
{
    return (
        collision(entity2->x, entity2->y) ||
        collision(entity2->x + entity2->size_x, entity2->y) ||
        collision(entity2->x, entity2->y + entity2->size_y) ||
        collision(entity2->x + entity2->size_x, entity2->y + entity2->size_y)
    );
}

bool Entity::collision(int _x, int _y)
{
    return (_x >= x && _x <= x + size_x && _y >= y && _y <= y + size_y);
}
