#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected :

    sf::Vector2f pos;
    sf::CircleShape shape;
    int radius;

public:
    Entity();
    Entity(sf::Vector2f pos,int radius);

    virtual void Update() = 0;
    virtual void draw(sf::RenderWindow& window);
    
    sf::Vector2f getPosition();
    int getRadius();
};
