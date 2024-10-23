#include "pch.h"
#include "Plant.h"

Plant::Plant() {}

Plant::Plant(sf::Vector2f pos, int radius) : Entity(pos, radius)
{
	shape.setFillColor(sf::Color::Blue);
}

Plant::~Plant() {}

void Plant::setState(Context::State) {}

Context::State Plant::getState() const
{
	return Context::State();
}

sf::Color Plant::getColor() const
{
	return sf::Color();
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
