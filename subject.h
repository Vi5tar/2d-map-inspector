#include <SFML/Graphics.hpp>

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
    private:
        int moveVelocity = 16;
        bool setupSprite(std::string);
        void updateSpriteTextureRect();
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect viewPort;
        Subject(std::string, float, float);
        void moveViewPortLeft();
        void moveViewPortRight();
        void moveViewPortUp();
        void moveViewPortDown();
};

#endif