#include "pch.h"
#include "Plant.h"
#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(sf::Vector2f pos, int radius) : Entity(pos, radius)
{
	shape.setFillColor(sf::Color::White);
}

Projectile::~Projectile()
{
}

void Projectile::setState(Context::State)
{
}

Context::State Projectile::getState() const
{
	return Context::State();
}

sf::Color Projectile::getColor() const
{
	return sf::Color();
}

void Projectile::Update()
{
}
