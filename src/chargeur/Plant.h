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
    int mAmmoCount = 5;
    int mMaxAmmo = 5;
    Context::State mState;
    Behaviour* mBehaviour;

    sf::Text ammo_text;
    sf::Font text_font;

public:

    Plant();
    Plant(sf::Vector2f pos, int radius);
    ~Plant();

    void setState(Context::State);
    Context::State getState() const;

    sf::Color getColor() const;
    int getAmmoCount() const;
    void refillMagazine();

    void shoot();
    void reload();

    void Update();

    Behaviour* getBehaviour() const { return mBehaviour; }
    void drawAmmoCount(sf::RenderWindow& window);

private :
    void setupBehaviour();
    void setBehaviour(Behaviour* behaviour);


};
