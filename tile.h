#include <SFML/Graphics.hpp>

#ifndef TILE_H
#define TILE_H

class Tile
{
    public:
        sf::Image image;
        int id;
        Tile(std::string, int);
        bool matches(sf::Image, sf::IntRect);
        std::vector<std::vector<sf::Color>> getColorMap();
};

#endif