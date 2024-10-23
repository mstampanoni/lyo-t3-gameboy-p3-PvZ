#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Context.h"
#include "Behaviour.h"
#include <iostream>

class Plant
{
    sf::Vector2f mPosition;
    std::string mName;
    int mAmmoCount, mMaxAmmo;
    Context::State mState;
    Behaviour* mBehaviour;
public:

    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant();

    void setState(Context::State);
    Context::State getState() const;

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
    int getAmmoCount() const;
    void refillMagazine();

    bool shoot();

    void Update();
};
