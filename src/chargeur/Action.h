#pragma once

#include "Plant.h"
#include "Playground.h"
#include <chrono>

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
    std::chrono::high_resolution_clock::time_point startTime;

    void Start(Plant* Plant) override 
    {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void Update(Plant* Plant) override
    {
        auto currentTime = std::chrono::high_resolution_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

        if (elapsed >= 2) 
        {
            Plant->shoot();
            startTime = std::chrono::high_resolution_clock::now();
        }
    }

    void End(Plant* Plant)  override {};
};


class ReloadingAction : public Action
{
public:
    std::chrono::high_resolution_clock::time_point startTime;

    void Start(Plant* Plant) override
    {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void Update(Plant* Plant) override
    {
        auto currentTime = std::chrono::high_resolution_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

        if (elapsed >= 4) {
            Plant->reload();
            startTime = std::chrono::high_resolution_clock::now();
        }
    }

    void End(Plant* Plant)  override {};
};
