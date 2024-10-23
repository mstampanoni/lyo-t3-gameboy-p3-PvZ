#include "pch.h"
#include <SFML/Graphics.hpp>

#include "Playground.h"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(650, 400), "PvZ Game");

    Playground* playground = Playground::instantiate();

    if (!playground)
    {
        return -1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        sf::Event dummy_event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            playground->handleUserInput(event, window);
        }
        window.clear();
        playground->draw(window);
        playground->update();
        window.display();
    }

    return 0;
}