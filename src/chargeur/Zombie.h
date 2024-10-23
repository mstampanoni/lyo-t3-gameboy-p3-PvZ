#pragma once
#include "Entity.h"

class Zombie : public Entity
{
public:
    Zombie(sf::Vector2f pos, int radius);

    void move();  
    void Update() override;  // Surcharger Update
};

