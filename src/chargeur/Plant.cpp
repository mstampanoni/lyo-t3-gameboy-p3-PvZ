#include "pch.h"
#include "Plant.h"
#include "Action.h"
#include "Transition.h"
#include "TextManager.h"

Plant::Plant() {}

Plant::Plant(sf::Vector2f pos, int radius) : Entity(pos, radius), mState(Context::State::Idle), mBehaviour(new Behaviour())
{
    shape.setFillColor(sf::Color::Blue);

    Action* idle_action = new IdleAction();
    Action* shooting_action = new ShootingAction();

    Transition* idle_to_shooting = new Transition();
    idle_to_shooting->addCondition(new ZombieInRangeCondition());
    idle_to_shooting->setTargetState(Context::State::Shooting);

    mBehaviour->AddAction(Context::State::Idle, idle_action);
    mBehaviour->AddTransition(Context::State::Idle, idle_to_shooting);

    mBehaviour->AddAction(Context::State::Shooting, shooting_action);

    Transition* shooting_to_idle = new Transition();
    shooting_to_idle->addCondition(new NoZombieInRangeCondition());
    shooting_to_idle->setTargetState(Context::State::Idle);

    mBehaviour->AddTransition(Context::State::Shooting, shooting_to_idle);

    Action* reloading_action = new ReloadingAction();

    Transition* idle_to_reload = new Transition();
    idle_to_reload->addCondition(new ReloadingCondition());
    idle_to_reload->setTargetState(Context::State::Reload);

    mBehaviour->AddAction(Context::State::Reload, reloading_action);

    mBehaviour->AddTransition(Context::State::Idle, idle_to_reload);
}

Plant::~Plant() {}

void Plant::setState(Context::State new_state)
{
    mState = new_state;
    mBehaviour->Start(this);
}

Context::State Plant::getState() const
{
	return mState;
}

sf::Color Plant::getColor() const
{
	return sf::Color::Blue;
}

int Plant::getAmmoCount() const
{
	return mAmmoCount;
}

void Plant::refillMagazine()
{
}

void Plant::shoot()
{
    if (mAmmoCount > 0) {
        Playground::getInstance()->addProjectile(sf::Vector2f(pos.x, pos.y + radius / 2));
        mAmmoCount--;
    }
}

void Plant::reload()
{
    mAmmoCount = mMaxAmmo;
}

void Plant::Update()
{
    mBehaviour->Update(this);
}

void Plant::drawAmmoCount(sf::RenderWindow& window)
{

    TextManager* text_manager = TextManager::getInstance();

	text_manager->text.setString(std::to_string(mAmmoCount));

	text_manager->text.setPosition(pos.x, pos.y + radius);

    window.draw(text_manager->text);
}
