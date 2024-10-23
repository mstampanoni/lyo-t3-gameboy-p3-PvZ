#include "pch.h"
#include "Plant.h"

Plant::Plant()
{
}

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
}

Plant::~Plant()
{
}

void Plant::setState(Context::State)
{
}

Context::State Plant::getState() const
{
	return Context::State();
}

sf::Color Plant::getColor() const
{
	return sf::Color();
}

sf::Vector2f Plant::getPosition() const
{
	return sf::Vector2f();
}

int Plant::getAmmoCount() const
{
	return 0;
}

void Plant::refillMagazine()
{
}

bool Plant::shoot()
{
	return false;
}

void Plant::Update()
{
}
