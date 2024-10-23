#include "pch.h"
#include "Entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pos, sf::Vector2f dim)
{
	this->pos = pos;
	this->dim = dim;
}
