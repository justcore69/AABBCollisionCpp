#pragma once
#include <SFML/Graphics.hpp>

#include "Wall.h"

class Player : public sf::RectangleShape {
public:
    float speed = 0.1f;

    Player(sf::Vector2f _size);

    void move(sf::Vector2f _dir);
    bool checkCollision(Wall &_wall);
};

