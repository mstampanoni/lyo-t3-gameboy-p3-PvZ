#pragma once
#include "Action.h"
class IdleAction : public Action
{
public:
    void Start(Plant* Plant);
    void Update(Plant* Plant);
    void End(Plant* Plant);
};

