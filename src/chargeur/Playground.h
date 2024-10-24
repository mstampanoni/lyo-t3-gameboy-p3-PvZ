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

	std::vector<int> rows = { 50,150,250,350 };

	Playground();
	void checkCollision(std::vector<Plant*>& mPlants, std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombies);

	void addZombie(sf::Vector2f pos);
	void addPlant();

	int getNearestRow(sf::Vector2i mouse_pos);
	bool isZombieInSameRow(Plant* plant, Zombie* zombie);

public:

	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);
	bool isZombieInRange(Plant* plant, Zombie* zombie, float range);
	const std::vector<Zombie*>& getZombies();
	void addProjectile(sf::Vector2f pos);
};