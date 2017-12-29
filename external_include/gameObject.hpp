#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class gameObject
{
    public:
        sf::Vector2f position;
        virtual void render(sf::RenderWindow* Window) = 0;
};

#endif //GAME_OBJECT_H