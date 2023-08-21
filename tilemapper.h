#include <SFML/Graphics.hpp>
#include "tile.h"

#ifndef TILEMAPPER_H
#define TILEMAPPER_H

class TileMapper
{
    public:
        sf::Image imageToMap;
        sf::IntRect areaToCompare;
        std::vector<Tile> tiles;
        TileMapper(sf::Image, sf::IntRect, std::vector<Tile>);
        void map();
};

#endif