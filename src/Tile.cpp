#include "Tile.hpp"

#include <SFML/Window.hpp>
#include <iostream>

void Tile::render(sf::RenderWindow* Window)
{
	Window->draw(*this);
}

Tile::Tile()
{
	setOrigin(16,16);
}

Tile::~Tile()
{

}

void Tile::setTilePosition(float x, float y)
{
	setPosition(x * 32, y * 32);
}