#pragma once
#include "Entity.h"
#include <SFML/System/Clock.hpp>  

class Zombie : public Entity
{
public:
    Zombie(sf::Vector2f pos, int radius);

    void Update() override;

    //faire un behviour normalement
    void startAttack();  
    void stopAttack();   

    float mSpeed = 0.01f;
    bool isAttacking = false;  
    sf::Clock attackClock;     
    sf::Time attackDuration = sf::seconds(3);  

private:
    bool attackInProgress = false;  
};
