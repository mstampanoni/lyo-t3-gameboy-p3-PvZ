#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    Entity(sf::Vector2f pos, int radius);

    sf::Vector2f pos;
    int radius;

    virtual void Update() = 0;

    /*sf::Vector2f getPosition();
    void setPosition(sf::Vector2f new_Position);*/
};