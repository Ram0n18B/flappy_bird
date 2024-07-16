#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/strategies/HardMode.hpp>

HardMode::HardMode(StateMachine* sm, std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
    : BaseStrategy{sm}
{
    world = _world;
    bird = _bird;
}

void HardMode::handle_inputs(const sf::Event& event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) 
    {
        state_machine->change_state("pause", world, bird);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        bird->movingLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        bird->movingRight();
    }
    else if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left)) 
    {
        bird->stopMovingX();
    }
}

void HardMode::update(float dt) noexcept
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

void HardMode::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(bird->getScore()), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}

void HardMode::spawn_logs(float& logs_spawn_timer, std::mt19937& rng, float& last_log_y, std::list<std::shared_ptr<LogPair>>& logs, Factory<LogPair>& log_factory) noexcept
{
    logs_spawn_timer = 0.f;
    std::uniform_int_distribution<int> dist{-20, 20};
    float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(last_log_y + dist(rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));
    last_log_y = y;
    std::shared_ptr<Log> _top;
    std::shared_ptr<Log> _bottom;
    if(dist(rng) % 4 == 0)
    {
        _top = std::make_shared<MovingLog>(Settings::VIRTUAL_WIDTH, y + Settings::LOG_HEIGHT, true);
        _bottom = std::make_shared<MovingLog>(Settings::VIRTUAL_WIDTH, y + Settings::LOGS_GAP + Settings::LOG_HEIGHT, false);
    }
    else
    {
        _top = std::make_shared<StaticLog>(Settings::VIRTUAL_WIDTH, y + Settings::LOG_HEIGHT, true);
        _bottom = std::make_shared<StaticLog>(Settings::VIRTUAL_WIDTH, y + Settings::LOGS_GAP + Settings::LOG_HEIGHT, false);
    }
    logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y, _top, _bottom));
}