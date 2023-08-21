#include "tile.h"

Tile::Tile(std::string filename, int id)
{
    this->id = id;
    image.loadFromFile(filename);
}

bool Tile::matches(sf::Image imageToCompare, sf::IntRect areaToCompare)
{
    for (int j = areaToCompare.top; j < areaToCompare.top + areaToCompare.height; j++)
    {
        for (int i = areaToCompare.left; i < areaToCompare.left + areaToCompare.width; i++)
        {
            sf::Color examinedPixelColor = imageToCompare.getPixel(i, j);
            sf::Color controlPixelColor = image.getPixel(i - areaToCompare.left, j - areaToCompare.top);
            if (examinedPixelColor != controlPixelColor)
            {
                return false;
            }
        }
    }
    return true;
}