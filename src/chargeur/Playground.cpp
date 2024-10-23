#include "pch.h"
#include "Playground.h"
#include "Zombie.h"
namespace {
	static Playground* instance = nullptr;
}

Playground::Playground() {

}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombie)
{
}

Playground* Playground::instantiate()
{
	if (!instance)
	{
		instance = new Playground();
		return instance;
	}
	return nullptr;
}

Playground* Playground::getInstance()
{
	return instance;
}

Playground::~Playground()
{
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mZombies.size(); i++) {

		int radius = 20;
		sf::CircleShape shape(radius);

		shape.setPosition(mZombies[i]->x, mZombies[i]->y);
		shape.setOrigin(radius, radius);
		shape.setFillColor(sf::Color(255, 0, 0));

		window.draw(shape);
	}
}

void Playground::update()
{
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

		mZombies.push_back(new Zombie(mouse_pos.x, mouse_pos.y));
	}
}
