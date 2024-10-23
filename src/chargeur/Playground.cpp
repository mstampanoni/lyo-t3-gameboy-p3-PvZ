#include "pch.h"
#include "Playground.h"
#include "Zombie.h"
#include "Projectile.h"

namespace {
	static Playground* instance = nullptr;
}

Playground::Playground() {

}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombie)
{
    for (auto& projectile : mProjectiles)
    {
        for (auto& zombie : mZombies)
        {
            if (projectile->pos.x < zombie->pos.x + zombie->dim.x &&
                projectile->pos.x + projectile->dim.x > zombie->pos.x &&
                projectile->pos.y < zombie->pos.y + zombie->dim.y &&
                projectile->pos.y + projectile->dim.y > zombie->pos.y)
            {
                delete projectile;
                delete zombie;

                mProjectiles.erase(std::remove(mProjectiles.begin(), mProjectiles.end(), projectile), mProjectiles.end());
                mZombies.erase(std::remove(mZombies.begin(), mZombies.end(), zombie), mZombies.end());

                break;
            }
        }
    }
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
