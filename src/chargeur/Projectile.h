#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Context.h"
#include "Behaviour.h"
#include <iostream>
#include "Entity.h"

class Projectile : public Entity
{
    std::string mName;
    int mAmmoCount, mMaxAmmo;
    Context::State mState;
    Behaviour* mBehaviour;

public:

    Projectile();
    Projectile(
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Projectile();

    void setState(Context::State);
    Context::State getState() const;

    sf::Color getColor() const;

    void Update();
};