#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    Entity(sf::Vector2f pos, sf::Vector2f dim);

    sf::Vector2f pos;
    sf::Vector2f dim;

    virtual void Update() = 0;
};
