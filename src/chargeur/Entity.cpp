#include "pch.h"
#include "Entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pos, int radius) : pos(pos) , radius(radius)
{
    shape.setPosition(pos);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);  
}

void Entity::draw(sf::RenderWindow& window)
{
    shape.setPosition(pos);  
    window.draw(shape);
}

sf::Vector2f Entity::getPosition()
{
    return sf::Vector2f();
}

int Entity::getRadius()
{
    return 0;
}
