#include "pch.h"
#include "Playground.h"
#include "Zombie.h"
#include "Projectile.h"

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
