/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class BaseState.
*/

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

class StateMachine;
class World;
class Bird;

class BaseStrategy
{
public:
    BaseStrategy(StateMachine* sm ) : state_machine(sm) {}

    virtual ~BaseStrategy() {}

    //virtual void enter(std::shared_ptr<World> world, std::shared_ptr<Bird> bird) noexcept {}

    virtual void handle_inputs(const sf::Event& event) noexcept {}

    virtual void update(float dt) noexcept {}

    virtual void render(sf::RenderTarget& target) const noexcept {}


protected:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    StateMachine* state_machine;
};