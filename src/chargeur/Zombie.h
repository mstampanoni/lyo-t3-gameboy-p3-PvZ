#pragma once
#include "Entity.h"

class Zombie : public Entity{
public:

	Zombie(int x, int y);

	void move();
	
	//float mSpeed;
};