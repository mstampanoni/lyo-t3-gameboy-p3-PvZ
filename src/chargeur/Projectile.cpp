#include "pch.h"
#include "Plant.h"
#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(Behaviour* plant_behaviour, int ammo_count)
{
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
