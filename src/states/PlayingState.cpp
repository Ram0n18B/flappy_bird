/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>
#include <src/strategies/NormalMode.hpp>
#include <src/strategies/HardMode.hpp>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    bird = _bird;

    if (current_strategy == nullptr && Settings::gameMode == 0) 
    {
        current_strategy = std::make_shared<NormalMode>(state_machine, world, bird);
    }
    else if (current_strategy == nullptr && Settings::gameMode == 1) 
    {
        current_strategy = std::make_shared<HardMode>(state_machine, world, bird);
    }
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    current_strategy->handle_inputs(event);
}

void PlayingState::update(float dt) noexcept
{
    current_strategy->update(dt);
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    current_strategy->render(target);
}