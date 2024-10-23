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
    //for (auto& projectile : mProjectiles)
    //{
    //    for (auto& zombie : mZombies)
    //    {
    //        if (projectile->pos.x < zombie->pos.x + zombie->radius &&
    //            projectile->pos.x + projectile->radius > zombie->pos.x &&
    //            projectile->pos.y < zombie->pos.y + zombie->radius &&
    //            projectile->pos.y + projectile->radius > zombie->pos.y)
    //        {
    //            delete projectile;
    //            delete zombie;

    //            mProjectiles.erase(std::remove(mProjectiles.begin(), mProjectiles.end(), projectile), mProjectiles.end());
    //            mZombies.erase(std::remove(mZombies.begin(), mZombies.end(), zombie), mZombies.end());

    //            break;
    //        }
    //    }
    //}
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
	for (int i = 0; i < mZombies.size(); i++) {

		int radius = 20;
		sf::CircleShape shape(radius);

		shape.setPosition(mZombies[i]->pos.x, mZombies[i]->pos.y);
		shape.setOrigin(radius, radius);
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setOutlineThickness(5);
		shape.setOutlineColor(sf::Color(134, 1, 17));

		window.draw(shape);
	}
}

void Playground::update()
{
	for (int i = 0; i < mZombies.size(); i++) {
		mZombies[i]->Update();
	}
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

		sf::Vector2f spawn_pos(650, getNearestRow(mouse_pos));

		mZombies.push_back(new Zombie(spawn_pos, 50));
	}
}
