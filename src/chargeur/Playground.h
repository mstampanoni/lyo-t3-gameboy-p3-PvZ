#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Plant;
class Projectile;
class Zombie;

class Playground
{
private:

	std::vector<Plant*> mPlants;
	std::vector<Zombie*> mZombies;
	std::vector<Projectile*> mProjectiles;

	Playground();
	void checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombies);

	void addZombie(sf::Vector2f pos);
	void addProjectile(sf::Vector2f pos);
	void addPlant();

public:

	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);
};