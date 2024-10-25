#include "pch.h"
#include "Zombie.h"

Zombie::Zombie(sf::Vector2f pos, int radius) : Entity(pos, radius)
{
    shape.setFillColor(sf::Color::Red);
}

void Zombie::Update()
{
    if (!isAttacking)
    {
        this->pos.x -= mSpeed;  
    }
    else
    {
        if (attackClock.getElapsedTime() >= attackDuration)
        {
            stopAttack();  
        }
    }
}

void Zombie::startAttack()
{
    isAttacking = true; 
    attackClock.restart();  
}

void Zombie::stopAttack()
{
    isAttacking = false;  
}
