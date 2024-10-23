#pragma once

#include "Plant.h"
#include "Playground.h"

class Action
{
public:
    virtual void Start(Plant* Plant) = 0;
    virtual void Update(Plant* Plant) = 0;
    virtual void End(Plant* Plant) = 0;
};

class IdleAction : public Action
{
public:
    void Start(Plant* Plant) override {};
    void Update(Plant* Plant)  override {};
    void End(Plant* Plant)  override {};
};

class ShootingAction : public Action
{
public:
    void Start(Plant* Plant) override 
    {
        Playground::getInstance()->addProjectile(Plant->getPosition());
    }

    void Update(Plant* plant) override
    {
        plant->shoot();
    }

    void End(Plant* Plant)  override {};
};
