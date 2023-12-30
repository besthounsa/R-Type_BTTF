#include "Entity.hpp"

using namespace std;

static int T = 0;

Entity::Entity()
{
    _id = T++;
}

string Entity::getId()
{
    return (to_string(_id));
}
