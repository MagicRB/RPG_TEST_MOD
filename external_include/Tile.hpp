#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "gameObject.hpp"

class Tile : public sf::Sprite, public gameObject
{
	public:
		Tile();
		~Tile();

		virtual void render(sf::RenderWindow* Window);

		void setTilePosition(float x, float y);
	protected:

	private:

};

#endif // TILE_H