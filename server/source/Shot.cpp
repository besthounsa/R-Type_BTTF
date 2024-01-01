#include "../include/Shot.hpp"

using namespace std;

Shot::Shot(std::shared_ptr<Client> _client) :
    Entity(_client->x + 50, _client->y + 12, 30, 30)
{
    client = _client;
}
