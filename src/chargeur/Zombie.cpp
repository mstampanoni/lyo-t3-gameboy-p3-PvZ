#include "pch.h"
#include "Zombie.h"

Zombie::Zombie(sf::Vector2f pos, int radius) : Entity(pos, radius)
{
    shape.setFillColor(sf::Color::Red);  
}

void Zombie::Update()
{
	this->pos.x -= mSpeed;
}
