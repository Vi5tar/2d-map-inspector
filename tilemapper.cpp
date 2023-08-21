#include <iostream>
#include <fstream>
#include "tilemapper.h"
#include "tile.h"

TileMapper::TileMapper(sf::Image imageToMap, sf::IntRect startTileLocation, std::vector<Tile> tiles)
{
    this->imageToMap = imageToMap;
    this->areaToCompare = startTileLocation;
    this->tiles = tiles;
}

void TileMapper::map()
{
    std::ofstream output;
    output.open("map.txt");

    for (int j = 0; j < imageToMap.getSize().y / areaToCompare.height; j++)
        {
            int left = areaToCompare.left;
            for (int i = 0; i < imageToMap.getSize().x / areaToCompare.width; i++)
            {
                // NOTE: out of bounds check
                if (areaToCompare.left + areaToCompare.width > imageToMap.getSize().x)
                {
                    break;
                }
                else
                {
                    bool matched = false;
                    for (Tile tile : tiles)
                    {
                        if (tile.matches(imageToMap, areaToCompare))
                        {
                            matched = true;
                            std::cout << "The area (" << areaToCompare.getPosition().x << ", " << areaToCompare.getPosition().y << ") is " << tile.id << "." << std::endl;
                            output << tile.id << " ";
                            break;
                        }
                    }
                    if (!matched)
                    {
                        std::cout << "The area (" << areaToCompare.getPosition().x << ", " << areaToCompare.getPosition().y << ") is not a known tile." << std::endl;
                        output << "00"
                               << " ";
                    }
                    areaToCompare.left += areaToCompare.width;
                }
            }
            areaToCompare.left = left;
            areaToCompare.top += areaToCompare.height;
            output << std::endl;

            // NOTE: out of bounds check
            if (areaToCompare.top + areaToCompare.height > imageToMap.getSize().y)
            {
                break;
            }
        }

        output.close();
    }