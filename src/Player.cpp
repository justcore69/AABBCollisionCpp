#include <iostream>
#include <string>

#include "Player.h"

Player::Player(sf::Vector2f _size){
	setSize(_size);
}

void Player::move(sf::Vector2f _dir){
    setPosition(getPosition().x + _dir.x * speed, getPosition().y + _dir.y * speed);
}

bool Player::checkCollision(Wall& _wall) {
    float pX = getPosition().x;
    float pY = getPosition().y;
    float pW = getSize().x;
    float pH = getSize().y;

    float wX = _wall.getPosition().x;
    float wY = _wall.getPosition().y;
    float wW = _wall.getSize().x;
    float wH = _wall.getSize().y;

    if (pX < wX + wW && pX + pW > wX && pY < wY + wH && pH + pY > wY)
    {
        std::cout << "Collision check: True\n";

        // Calculate the overlap between the player and the wall
        float overlapX = 0.0f;
        float overlapY = 0.0f;

        if (pX < wX) {
            overlapX = pX + pW - wX;
        }
        else {
            overlapX = wX + wW - pX;
        }
            
        if (pY < wY) {
            overlapY = pY + pH - wY;
        }
        else {
            overlapY = wY + wH - pY;
        }


        // Resolve the collision by moving the player back along the direction they came from
        if (overlapX < overlapY)
        {
            if (pX < wX)
                move(sf::Vector2f(-overlapX*2, 0.0f));
            else
                move(sf::Vector2f(overlapX * 2, 0.0f));
        }
        else
        {
            if (pY < wY)
                move(sf::Vector2f(0.0f, -overlapY * 2));
            else
                move(sf::Vector2f(0.0f, overlapY * 2));
        }

        return true;
    }

    std::cout << "Collision check: False\n";
    return false;
}
