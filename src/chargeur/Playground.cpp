#include "pch.h"
#include "Playground.h"
#include "Zombie.h"

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombie)
{
}

Playground* Playground::instantiate()
{
	return nullptr;
}

Playground* Playground::getInstance()
{
	return nullptr;
}

Playground::~Playground()
{
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i > mZombies.size(); i++) {
		
	}
}

void Playground::update()
{
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2i mouse_pos = sf::Mouse::getPosition();
		mZombies.push_back(new Zombie(mouse_pos.x, mouse_pos.y));
	}
}
