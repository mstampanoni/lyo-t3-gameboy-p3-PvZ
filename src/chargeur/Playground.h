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
	Playground();
	void checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mZombies);
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);
};