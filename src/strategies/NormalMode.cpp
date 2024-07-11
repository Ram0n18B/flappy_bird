#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/strategies/NormalMode.hpp>

NormalMode::NormalMode(StateMachine* sm, std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
    : BaseStrategy{sm}
{
    world = _world;
    bird = _bird;
}

void NormalMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) 
    {
        state_machine->change_state("pause", world, bird);
    }
}

void NormalMode::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    if (world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        bird->scoreReset();
        state_machine->change_state("count_down", world, bird);
        return;
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        bird->addScore();
        Settings::sounds["score"].play();
    }
}

void NormalMode::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(bird->getScore()), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}