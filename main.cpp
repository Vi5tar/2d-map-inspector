#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "subject.cpp"
#include "tile.cpp"
#include "tilemapper.cpp"

int main()
{
    const bool mapTiles = false;

    const double targetFPS = 60.0;
    const double targetFrameTime = 1.0 / targetFPS;
    float windowWidth = 800;
    float windowHeight = 592;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Image Inspector");

    // image being inspected
    Subject subject = Subject("assets/dw-world.png", windowWidth, windowHeight);

    // reticle
    sf::RectangleShape reticle(sf::Vector2f(16, 16));
    reticle.setFillColor(sf::Color::Transparent);
    reticle.setOutlineColor(sf::Color::Red);
    reticle.setOutlineThickness(-2);
    reticle.setPosition((windowWidth / 2) - 1, (windowHeight / 2) + 1);

    if (mapTiles)
    {
        TileMapper tileMapper = TileMapper(
            subject.sprite.getTexture()->copyToImage(),
            sf::IntRect(15, 9, 16, 16),
            std::vector<Tile>{
                Tile("assets/dw-water.png", 21),
                Tile("assets/dw-mountain.png", 14),
                Tile("assets/dw-trees.png", 11),
                Tile("assets/dw-grass.png", 10),
                Tile("assets/dw-seBeach.png", 27),
                Tile("assets/dw-hill.png", 13),
                Tile("assets/dw-nwBeach.png", 29),
                Tile("assets/dw-swBeach.png", 28),
                Tile("assets/dw-desert.png", 12),
                Tile("assets/dw-swamp.png", 20),
                Tile("assets/dw-neBeach.png", 26),
                Tile("assets/dw-weBeach.png", 35),
                Tile("assets/dw-sBeach.png", 24),
                Tile("assets/dw-nwsBeach.png", 33),
                Tile("assets/dw-nBeach.png", 22),
                Tile("assets/dw-bridge.png", 17),
                Tile("assets/dw-grassStairs.png", 19),
                Tile("assets/dw-wBeach.png", 25),
                Tile("assets/dw-eBeach.png", 23),
                Tile("assets/dw-nesBeach.png", 31),
                Tile("assets/dw-grassCave.png", 18),
                Tile("assets/dw-nsBeach.png", 34),
                Tile("assets/dw-wneBeach.png", 30),
                Tile("assets/dw-castle.png", 40),
                Tile("assets/dw-town.png", 41),
                Tile("assets/dw-brick.png", 50)});
        tileMapper.map();
    }

    while (window.isOpen())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        // App logic and rendering code here
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                    subject.moveViewPortLeft();
                    break;
                case sf::Keyboard::Right:
                    subject.moveViewPortRight();
                    break;
                case sf::Keyboard::Up:
                    subject.moveViewPortUp();
                    break;
                case sf::Keyboard::Down:
                    subject.moveViewPortDown();
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();

        window.draw(subject.sprite);
        window.draw(reticle);

        window.display();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> frameDuration = endTime - startTime;

        // Calculate the time to sleep to achieve the target frame time
        double sleepTime = targetFrameTime - frameDuration.count();
        if (sleepTime > 0)
        {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }
    }

    return 0;
}
