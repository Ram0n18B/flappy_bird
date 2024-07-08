#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/strategies/HardMode.hpp>

HardMode::HardMode(StateMachine* sm, std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
    : BaseStrategy{sm}
{
    //TODO
}

void HardMode::handle_inputs(const sf::Event& event) noexcept
{
    //TODO
}

void HardMode::update(float dt) noexcept
{
    //TODO
}

void HardMode::render(sf::RenderTarget& target) const noexcept
{
    //TODO
}