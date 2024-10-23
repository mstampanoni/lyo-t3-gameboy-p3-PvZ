#pragma once
#include "Entity.h"

class Zombie : public Entity{
public:

	Zombie(sf::Vector2f pos, int radius);

	void Update() override;
	
	float mSpeed = 0.005f;
};