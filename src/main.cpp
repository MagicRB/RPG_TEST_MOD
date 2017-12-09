#include "main.h"

#include <iostream>
#include <map>

#include "test.hpp"
#include "Tile.hpp"

std::map<std::string, Tile> tile_defs;

std::vector<std::string> split(const char *str, char c = ' ')
{
    std::vector<std::string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
}

void controller(modAPI* mapi, sf::Event event)
{
    if (event.type == sf::Event::Closed) {
		mapi->grtWindow()->close();
	} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
		mapi->grtWindow()->close();
	}
}

void loadFromWorldLine(modAPI* mapi, std::string line)
{
    int i = 0;
				
    std::string operation;
    std::string arguments;

    while (line.at(i) != ' ')
    {
    	operation += line.at(i);
    	i++;
    }
    arguments = line.substr(i + 1, line.size() - 1);

    arguments.erase(std::remove(arguments.begin(), arguments.end(), ' '), arguments.end());

    std::vector<std::string> tokens = split(arguments.c_str(), ';');

    if (operation == ":TILE") {
    	tile_defs[tokens.at(0)] = Tile();
    	mapi->grtTexm()->addNewTexture(tokens.at(1));
    	mapi->grtTexm()->texture_map.at(tokens.at(1)).loadFromFile("Textures/" + tokens.at(1) + ".png");
    	tile_defs.at(tokens.at(0)).setTexture(mapi->grtTexm()->texture_map.at(tokens.at(1)));
    } else if (operation == ":CREATE") {
    	mapi->grtGom()->go_vector.push_back(new Tile(tile_defs.at(tokens.at(0))));
    	Tile* t = dynamic_cast<Tile*>(mapi->grtGom()->go_vector.at(mapi->grtGom()->go_vector.size() - 1));
    	t->setTilePosition(atoi(tokens.at(1).c_str()), atoi(tokens.at(2).c_str()));
    }
}

void initializeMod(modAPI* mapi)
{
    mapi->sorControl(controller);
    mapi->steWorldFileEntry(loadFromWorldLine);
}