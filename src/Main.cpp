#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Wall.h"

const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

bool keyW = false;
bool keyA = false;
bool keyS = false;
bool keyD = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "AABB Collision by @Pieceofsoil");

    //Initialize player
    Player player(sf::Vector2f(48, 48));
    player.setFillColor(sf::Color::Green);
    player.setPosition(sf::Vector2f(WIN_WIDTH / 2 - player.getSize().x / 2, WIN_HEIGHT / 2 - player.getSize().y / 2 + 30));

    //Initialize wall
    Wall wall(sf::Vector2f(96, 48));
    wall.setFillColor(sf::Color::Color(128, 128, 128, 255));
    wall.setPosition(sf::Vector2f(WIN_WIDTH / 2 - wall.getSize().x / 2, WIN_HEIGHT / 2 - wall.getSize().y / 2 - 48*2 + 30));

    int iteration = 0;
    while (window.isOpen()) /// GAME LOOP ///
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close(); //Close window if user pressed the cross button

            //Controls for the player

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                case(sf::Keyboard::W): keyW = true; break;
                case(sf::Keyboard::A): keyA = true; break;
                case(sf::Keyboard::S): keyS = true; break;
                case(sf::Keyboard::D): keyD = true; break;
                }
            }

            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code)
                {
                case(sf::Keyboard::W): keyW = false; break;
                case(sf::Keyboard::A): keyA = false; break;
                case(sf::Keyboard::S): keyS = false; break;
                case(sf::Keyboard::D): keyD = false; break;
                }
            }
        }

        if (keyW) player.move(sf::Vector2f(0, -1));
        if (keyA) player.move(sf::Vector2f(-1, 0));
        if (keyS) player.move(sf::Vector2f(0, 1));
        if (keyD) player.move(sf::Vector2f(1, 0));
         
        //Calculate physics

        if (iteration % 3 == 0) { // only in each 5th frame
            player.checkCollision(wall); /// AABB COLLISION IMPLEMENTATION IS HERE ///
        } 

        //Render shapes

        window.clear();

        window.draw(player);
        window.draw(wall);

        window.display();

        iteration++;
    }
    return 0;
}