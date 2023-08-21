#include "subject.h"

Subject::Subject(std::string filename, float windowWidth, float windowHeight)
{
    moveVelocity = 16;
    viewPort = sf::IntRect(0, 0, windowWidth, windowHeight);
    if (!setupSprite(filename))
    {
        return;
    }
}

void Subject::moveViewPortLeft()
{
    viewPort.left -= moveVelocity;
    updateSpriteTextureRect();
}

void Subject::moveViewPortRight()
{
    viewPort.left += moveVelocity;
    updateSpriteTextureRect();
}

void Subject::moveViewPortUp()
{
    viewPort.top -= moveVelocity;
    updateSpriteTextureRect();
}

void Subject::moveViewPortDown()
{
    viewPort.top += moveVelocity;
    updateSpriteTextureRect();
}

bool Subject::setupSprite(std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        return false;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(viewPort);
    return true;
}

void Subject::updateSpriteTextureRect()
{
    sprite.setTextureRect(viewPort);
}
