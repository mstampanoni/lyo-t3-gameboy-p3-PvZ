#pragma once
#include "Playground.h"
#include "Zombie.h"
#include "Plant.h"

class Condition
{
public:
    virtual bool Test(Plant* Plant) = 0;
};

class ZombieInRangeCondition : public Condition
{
public:
    bool Test(Plant* plant) override
    {
        for (auto zombie : Playground::getInstance()->getZombies())
        {
            if (zombie->getPosition().y == plant->getPosition().y)
            {
                return true;
            }
        }
        return false;
    }
};

class NoZombieInRangeCondition : public Condition
{
private:
    float mRange;

public:
    bool Test(Plant* plant) override
    {
        for (auto zombie : Playground::getInstance()->getZombies())
        {
            if (zombie->getPosition().y == plant->getPosition().y)
            {
                return false;
            }
        }
        return true;
    }
};
