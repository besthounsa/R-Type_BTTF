#pragma once

#include "Entity.hpp"
#include "Client.hpp"

class Shot : public Entity {
public:
    Shot(std::shared_ptr<Client> client);
    std::shared_ptr<Client> client;
};
