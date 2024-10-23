#include "pch.h"
#include "Plant.h"
#include "TextManager.h"

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
	return mAmmoCount;
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

void Plant::drawAmmoCount(sf::RenderWindow& window)
{

    TextManager* text_manager = TextManager::getInstance();

	text_manager->text.setString(std::to_string(mAmmoCount));

	text_manager->text.setPosition(pos.x, pos.y + radius);

    window.draw(text_manager->text);
}
