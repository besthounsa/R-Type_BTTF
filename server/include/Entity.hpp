#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread.hpp>
#include <thread>
#include <vector>
#include <tuple>
#include <mutex>
#include <iomanip>

#define WIDTH 1100
#define HEIGHT 600

class Entity {
public:
    Entity(double _x, double _y, double _size_x, double _size_y);
    virtual ~Entity() {}
    bool collision(std::shared_ptr<Entity> entity2);
    bool collision(int x, int y);

    double x, y;
    int size_x, size_y;
    int id;
    static int T;
};

std::vector<std::string> split(std::string str, char sep);
