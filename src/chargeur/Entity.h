#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    Entity(sf::Vector2f pos, sf::Vector2f dim);

    sf::Vector2f pos;
    sf::Vector2f dim;

    /*sf::Vector2f getPosition();
    void setPosition(sf::Vector2f new_Position);*/
};