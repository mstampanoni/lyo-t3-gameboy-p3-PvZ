#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Context.h"
#include "Behaviour.h"
#include <iostream>
#include "Entity.h"

class Plant : public Entity
{
    std::string mName;
    int mAmmoCount, mMaxAmmo;
    Context::State mState;
    Behaviour* mBehaviour;

public:

    Plant();
    Plant(sf::Vector2f pos, int radius);
    ~Plant();

    void setState(Context::State);
    Context::State getState() const;

    sf::Color getColor() const;
    int getAmmoCount() const;
    void refillMagazine();

    bool shoot();

    void Update();

    Behaviour* getBehaviour() const { return mBehaviour; }

private :
    void setupBehaviour();
    void setBehaviour(Behaviour* behaviour);

};
