#include "pch.h"
#include "Entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pos, int radius)
{
	this->pos = pos;
	this->radius = radius;
}
