#include "pch.h"
#include "Playground.h"
#include "Zombie.h"
#include "Projectile.h"
#include "Plant.h"
#include "Entity.h"
#include <algorithm>

namespace {
    static Playground* instance = nullptr;
}

Playground::Playground () { addPlant(); }

void Playground::addZombie(sf::Vector2f pos)
{
    mZombies.push_back(new Zombie(pos, 10));
}

void Playground::addProjectile(sf::Vector2f pos)
{
    mProjectiles.push_back(new Projectile(pos, 5));
}

void Playground::addPlant()
{
    mPlants.push_back(new Plant(sf::Vector2f(10, 50), 10));
    mPlants.push_back(new Plant(sf::Vector2f(10, 150), 10));
    mPlants.push_back(new Plant(sf::Vector2f(10, 250), 10));
    mPlants.push_back(new Plant(sf::Vector2f(10, 350), 10));
}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombies)
{
    for (auto& projectile : mProjectiles)
    {
        for (auto& zombie : mZombies)
        {
            if (projectile->getPosition().x < zombie->getPosition().x + zombie->getRadius() * 2 &&
                projectile->getPosition().x + projectile->getRadius() * 2 > zombie->getPosition().x &&
                projectile->getPosition().y < zombie->getPosition().y + zombie->getRadius() * 2 &&
                projectile->getPosition().y + projectile->getRadius() * 2 > zombie->getPosition().y)
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

int Playground::getNearestRow(sf::Vector2i mouse_pos)
{
	if (mouse_pos.y >= 0 && mouse_pos.y <= 100) {
		return 50;
	} else if (mouse_pos.y > 100 && mouse_pos.y <= 200) {
		return 150;
	} else if (mouse_pos.y > 200 && mouse_pos.y <= 300) {
		return 250;
	} else {
		// else if (mouse_pos.y > 300 && mouse_pos.y <= 400) {
		return 350;
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
    for (auto& zombie : mZombies)
    {
        zombie->draw(window);
    }

    for (auto& projectile : mProjectiles)
    {
        projectile->draw(window);
    }

    for (auto& plant : mPlants)
    {
        plant->draw(window);
    }
		//shape.setPosition(mZombies[i]->pos.x, mZombies[i]->pos.y);
		//shape.setOrigin(radius, radius);
		//shape.setFillColor(sf::Color(255, 0, 0));
		//shape.setOutlineThickness(5);
		//shape.setOutlineColor(sf::Color(134, 1, 17));

		//window.draw(shape);
	}
}

void Playground::update()
{
    for (auto& zombie : mZombies)
    {
        zombie->Update();
    }

    for (auto& projectile : mProjectiles)
    {
        projectile->Update();
    }
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        addZombie(sf::Vector2f(mouse_pos.x, mouse_pos.y));
    }
}
