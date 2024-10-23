#include "pch.h"
#include "Transition.h"
#include "Plant.h"

void Transition::setTargetState(Context::State target_state)
{
    mTargetState = target_state;
}

void Transition::addCondition(Condition* condition)
{
    mConditions.push_back(condition);
}

void Transition::Try(Plant* Plant)
{
    int true_tests = 0;
    for (const auto& c : mConditions)
    {
        true_tests += c->Test(Plant);
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        Plant->setState(mTargetState);
    }
}
